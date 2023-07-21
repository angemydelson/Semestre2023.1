/*
 * Tarefa 02 - Testes em Circuitos Integrados
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

    matriz_adj_.resize(num_vertices);
    for (int i = 0; i < num_vertices; i++) { // ou i < matriz_adj_.size()
                                             // Esta observacao tambem vale
                                             // para lacos semelhantes neste
                                             // arquivo
        matriz_adj_[i].resize(num_vertices, 0);
    }
}

int Grafo::num_vertices() {
    return num_vertices_;
}

int Grafo::num_arestas() {
    return num_arestas_;
}

void Grafo::insere_aresta(Aresta e) {
    try {
        valida_aresta(e);
    } catch (...) {
        throw_with_nested(runtime_error("Erro na operacao "
            "insere_aresta(Aresta): a aresta " + e.to_string() + " eh "
            "invalida!"));
    }

    if ((matriz_adj_[e.v1][e.v2] == 0) && (e.v1 != e.v2)) {
        matriz_adj_[e.v1][e.v2] = 1;
        matriz_adj_[e.v2][e.v1] = 1;

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

    if (matriz_adj_[e.v1][e.v2] != 0) {
        matriz_adj_[e.v1][e.v2] = 0;
        matriz_adj_[e.v2][e.v1] = 0;

        num_arestas_--;
    }
}

bool Grafo::eh_caminho(vector<int> &seq_vertices) {
    if (seq_vertices.size() == 0) {
        throw(invalid_argument("Erro na operacao eh_caminho(vector<int> &): a"
            " sequencia de vertices eh vazia"));
    }

    vector<int> marcado(num_vertices_);

    marcado[seq_vertices[0]] = 1;
    for (unsigned i = 1; i < seq_vertices.size(); i++) {
        if ((marcado[seq_vertices[i]] != 0) ||
                (matriz_adj_[seq_vertices[i - 1]][seq_vertices[i]] == 0)) {
            return false;
        }

        marcado[seq_vertices[i]] = 1;
    }

    return true;
}

bool Grafo::existe_caminho_rec(int v, int w, vector<int> &marcado) {
    if (v == w) {
        return true;
    }

    marcado[v] = 1;
    for (int u = 0; u < num_vertices_; u++) {
        if (matriz_adj_[v][u] != 0) {
            if (marcado[u] == 0) {
                if (existe_caminho_rec(u, w, marcado)) {
                    return true;
                }
            }
        }
    }

    return false;
}

bool Grafo::existe_caminho(int v, int w) {
    vector<int> marcado(num_vertices_);

    return existe_caminho_rec(v, w, marcado);
}

bool Grafo::eh_conexo() {
    vector<int> marcado(num_vertices_);

    for (int v = 0; v < (num_vertices_ - 1); v++) {
        for (int w = (v + 1); w < num_vertices_; w++) {
            if (!existe_caminho_rec(v, w, marcado)) {
                return false;
            }

            fill(marcado.begin(), marcado.end(), 0);
        }
    }

    return true;
}

bool Grafo::eh_aciclico() {
    vector<int> marcado(num_vertices_);

    bool existe_ciclo = false;

    for (int v = 0; v < (num_vertices_ - 1); v++) {
        for (int w = (v + 1); w < num_vertices_; w++) {
            if (matriz_adj_[v][w] != 0) {
                remove_aresta(Aresta(v, w));
                if (existe_caminho_rec(v, w, marcado)) {
                    existe_ciclo = true;
                }
                insere_aresta(Aresta(v, w));

                if (existe_ciclo) {
                    return false;
                }

                fill(marcado.begin(), marcado.end(), 0);
            }
        }
    }

    return true;
}

void Grafo::imprime() {
    for (int v = 0; v < num_vertices_; v++) {
        cout << v << ":";
        for (int u = 0; u < num_vertices_; u++) {
            if (matriz_adj_[v][u] != 0) {
                cout << " " << u;
            }
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
