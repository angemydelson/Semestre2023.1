/*
 * Tarefa 01 - Grafo - Listas de Adjacencia
 *
 * GEN254 - Grafos - 2023/1
 *
 * Nome:      XXXX
 * Matricula: XXXX
 */

#include "Grafo.h"
#include <exception>
#include <stdexcept>
#include <algorithm>
#include <limits>
#include <string>
#include <iostream>

using namespace std;

Grafo::Grafo(int num_vertices) {
    if (num_vertices <= 0) {
        throw(invalid_argument("Erro no construtor Grafo(int): o numero de "
            "vertices " + to_string(num_vertices) + " eh invalido!"));
    }

    num_vertices_ = num_vertices;
    num_arestas_ = 0;

    listas_adj_.resize(num_vertices);
}

int Grafo::num_vertices() {
    return num_vertices_;
}

int Grafo::num_arestas() {
    return num_arestas_;
}

bool Grafo::tem_aresta(Aresta e) {
    try {
        valida_aresta(e);
    } catch (...) {
        throw_with_nested(runtime_error("Erro na operacao tem_aresta(Aresta):"
            " a aresta " + e.to_string() + " eh invalida!"));
    }

    for (auto u : listas_adj_[e.v1]) {
        if (u == e.v2) {
            return true;
        }
    }

    return false;
}

void Grafo::insere_aresta(Aresta e) {
    try {
        valida_aresta(e);
    } catch (...) {
        throw_with_nested(runtime_error("Erro na operacao "
            "insere_aresta(Aresta): a aresta " + e.to_string() + " eh "
            "invalida!"));
    }

    if (!tem_aresta(e) && (e.v1 != e.v2)) {
        listas_adj_[e.v1].push_front(e.v2);
        listas_adj_[e.v2].push_front(e.v1);

        num_arestas_++;
    }
}

void Grafo::remove_aresta(Aresta e) {
    try {
        valida_aresta(e);
    } catch (...) {
        throw_with_nested(runtime_error("Erro na operacao "
            "remove_aresta(Aresta): a aresta " + e.to_string() + " eh "
            "invalida!"));
    }

    bool grafo_tem_aresta = false;

    auto it = listas_adj_[e.v1].begin();
    while (it != listas_adj_[e.v1].end()) {
        if (*it == e.v2) {
            listas_adj_[e.v1].erase(it); // Apos esta operacao, o valor de it
                                         // nao eh mais valido
            grafo_tem_aresta = true;

            break;
        }

        it++;
    }

    if (grafo_tem_aresta) {
        auto it = listas_adj_[e.v2].begin();
        while (it != listas_adj_[e.v2].end()) {
            if (*it == e.v1) {
                listas_adj_[e.v2].erase(it); // Apos esta operacao, o valor de
                                             // it nao eh mais valido
    
                break;
            }
    
            it++;
        }

        num_arestas_--;
    }
}

int Grafo::grau(int v) {
    try {
        valida_vertice(v);
    } catch (...) {
        throw_with_nested(runtime_error("Erro na operacao grau(int): o "
            "vertice " + to_string(v) + " eh invalido!"));
    }

    return listas_adj_[v].size();
}

int Grafo::grau_maximo() {
    int grau_maximo = 0;
    for (auto v = 0; v < num_vertices_; v++) { // ou v < listas_adj_.size()
        grau_maximo = max(grau_maximo, grau(v));
    }

    return grau_maximo;
}

int Grafo::grau_minimo() {
    int grau_minimo = numeric_limits<int>::max();
    for (auto v = 0; v < num_vertices_; v++) { // ou v < listas_adj_.size()
        grau_minimo = min(grau_minimo, grau(v));
    }

    return grau_minimo;
}

void Grafo::imprime() {
    for (auto v = 0; v < num_vertices_; v++) { // ou v < listas_adj_.size()
        cout << v << ":";
        for (auto u : listas_adj_[v]) {
            cout << " " << u;
        }
        cout << "\n";
    }
}

void Grafo::valida_vertice(int v) {
    if ((v < 0) || (v >= num_vertices_)) {
        throw out_of_range("Indice de vertice invalido: " + to_string(v));
    }
}

void Grafo::valida_aresta(Aresta e) {
    valida_vertice(e.v1);
    valida_vertice(e.v2);
}
