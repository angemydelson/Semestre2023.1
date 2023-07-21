/*
 * Tarefa 03 - Viacao Grafeira
 *
 * GEN254 - Grafos - 2023/1
 *
 * Nome:      XXXX
 * Matricula: XXXX
 */

#include "Digrafo.h"
#include "Filapri_min.h"
#include <exception>
#include <stdexcept>
#include <algorithm>
#include <limits>
#include <string>
#include <iostream>

using namespace std;

Digrafo::Digrafo(int num_vertices) {
    if (num_vertices <= 0) {
        throw(invalid_argument("Erro no construtor Digrafo(int): o numero de "
            "vertices " + to_string(num_vertices) + " eh invalido!"));
    }

    num_vertices_ = num_vertices;
    num_arestas_ = 0;

    listas_adj_.resize(num_vertices);
}

int Digrafo::num_vertices() {
    return num_vertices_;
}

int Digrafo::num_arestas() {
    return num_arestas_;
}

bool Digrafo::tem_aresta(Aresta e) {
    try {
        valida_aresta(e);
    } catch (...) {
        throw_with_nested(runtime_error("Erro na operacao tem_aresta(Aresta):"
            " a aresta " + e.to_string() + " eh invalida!"));
    }

    for (auto &u : listas_adj_[e.v1]) {
        if (u.first == e.v2) {
            return true;
        }
    }

    return false;
}

void Digrafo::insere_aresta(Aresta e) {
    try {
        valida_aresta(e);
    } catch (...) {
        throw_with_nested(runtime_error("Erro na operacao "
            "insere_aresta(Aresta): a aresta " + e.to_string() + " eh "
            "invalida!"));
    }

    if (!tem_aresta(e) && (e.v1 != e.v2)) {
        listas_adj_[e.v1].push_front({e.v2, e.peso});

        num_arestas_++;
    }
}

void Digrafo::remove_aresta(Aresta e) {
    try {
        valida_aresta(e);
    } catch (...) {
        throw_with_nested(runtime_error("Erro na operacao "
            "remove_aresta(Aresta): a aresta " + e.to_string() + " eh "
            "invalida!"));
    }

    auto it = listas_adj_[e.v1].begin();
    while (it != listas_adj_[e.v1].end()) {
        if (it->first == e.v2) {
            listas_adj_[e.v1].erase(it); // Apos esta operacao, o valor de it
                                         // nao eh mais valido
            num_arestas_--;

            break;
        }

        it++;
    }
}

void Digrafo::dijkstra(int v, vector<int> &pai, vector<int> &dist_pond) {
    try {
        valida_vertice(v);
    } catch (...) {
        throw_with_nested(runtime_error("Erro na operacao dijkstra: o "
            "vertice " + to_string(v) + " eh invalido!"));
    }

    int w;

    for (w = 0; w < num_vertices_; w++) {
        pai[w] = -1;
        dist_pond[w] = numeric_limits<int>::max();
    }
    dist_pond[v] = 0;

    Filapri_min<int> f(num_vertices_);

    for (w = 0; w < num_vertices_; w++) {
        f.insere(w, dist_pond[w]);
    }

    while (!f.vazia()) {
        w = f.remove().first;

        if (dist_pond[w] < numeric_limits<int>::max()) {
            for (auto &u : listas_adj_[w]) {
                if (dist_pond[u.first] > (dist_pond[w] + u.second)) {
                    dist_pond[u.first] = (dist_pond[w] + u.second);
                    f.diminui_prio(u.first, dist_pond[u.first]);
                    pai[u.first] = w;
                }
            }
        }
    }
}

void Digrafo::imprime_caminhos_viaveis_arv(int v, vector<int> &pai,
        vector<int> &dist_pond, int dist_min) {
    try {
        valida_vertice(v);
    } catch (...) {
        throw_with_nested(runtime_error("Erro na operacao "
            "imprime_caminhos_viaveis_arv: o vertice " + to_string(v) + " eh "
            "invalido!"));
    }

    int u;
    int w;

    for (u = 0; u < num_vertices_; u++) {
        if (u == v) {
            continue;
        }

        if ((pai[u] == -1) || (dist_pond[u] < dist_min)) {
            cout << u << ": economicamente inviavel partindo de " << v <<
                "\n";
        }
        else {
            cout << u << ": " << dist_pond[u] << ", " << u;

            w = pai[u];
            while (w != -1) {
                cout << " " << w;

                w = pai[w];
            }

            cout << "\n";
        }
    }
}

void Digrafo::imprime_caminhos_viaveis(int v, int dist_min) {
    try {
        valida_vertice(v);
    } catch (...) {
        throw_with_nested(runtime_error("Erro na operacao "
            "imprime_caminhos_viaveis: o vertice " + to_string(v) + " eh "
            "invalido!"));
    }

    // Ponto de melhoria: Definir estes vetores como atributos da classe e
    // alocar memoria para eles apenas na primeira vez em que eles sao
    // utilizados
    vector<int> pai(num_vertices_);
    vector<int> dist_pond(num_vertices_);

    dijkstra(v, pai, dist_pond);
    imprime_caminhos_viaveis_arv(v, pai, dist_pond, dist_min);
}

void Digrafo::imprime() {
    for (auto v = 0; v < num_vertices_; v++) { // ou v < listas_adj_.size()
        cout << v << ":";
        for (auto &u : listas_adj_[v]) {
            cout << " " << u.first << "," << u.second;
        }
        cout << "\n";
    }
}

void Digrafo::valida_vertice(int v) {
    if ((v < 0) || (v >= num_vertices_)) {
        throw out_of_range("Indice de vertice invalido: " + to_string(v));
    }
}

void Digrafo::valida_aresta(Aresta e) {
    valida_vertice(e.v1);
    valida_vertice(e.v2);
}
