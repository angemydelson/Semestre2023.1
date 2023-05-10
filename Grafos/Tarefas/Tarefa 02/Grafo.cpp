#include "Grafo.h"
#include <iostream>

using namespace std;

Grafo::Grafo(int num_vertices) {
    num_vertices_ = num_vertices; 
    num_arestas_ = 0;
    matriz_adj_.resize(num_vertices);
    for (auto i = 0; i < num_vertices; i++) {
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
    if ((matriz_adj_[e.v1][e.v2] == 0) && (e.v1 != e.v2)) {
        matriz_adj_[e.v1][e.v2] = 1;
        matriz_adj_[e.v2][e.v1] = 1;
        num_arestas_++;
    }
}

void Grafo::remove_aresta(Aresta e) {
    if (matriz_adj_[e.v1][e.v2] != 0) {
        matriz_adj_[e.v1][e.v2] = 0;
        matriz_adj_[e.v2][e.v1] = 0;
        num_arestas_--;
    }
}

void Grafo::imprime() {
    for (auto i = 0; i < num_vertices_; i++) {
        cout << i << ":";
        for (auto j = 0; j < num_vertices_; j++) {
            if (matriz_adj_[i][j] != 0) {
                cout << " " << j;
            }
        }
        cout << "\n";
    }
}

bool Grafo::eh_caminho(int v, int w, int marcado[]) {
    if (v == w) {
        cout << v << "-";
        return true;
    }
    marcado[v] = 1;
    for (auto u = 0; u < num_vertices_; u++) {
        if (matriz_adj_[v][u] != 0) {
            if (marcado[u] == 0) {
                if (eh_caminho(u, w, marcado)) {
                    cout << v << "-";
                    return true;
                }
            } 
        }
    }
    return false;
}

bool Grafo::existe_caminho(int v, int w) {
    int num_vertices_ = num_vertices();
    int marcado[num_vertices_];
    for (auto i = 0; i < num_vertices_; i++) {
        marcado[i] = 0;
    }
    return eh_caminho(v, w, marcado);
}

bool Grafo::eh_conexo() {
    int num_vertices_ = num_vertices();
    int marcado[num_vertices_];
    // int marcado[];
    for (auto i = 0; i < num_vertices_; i++) {
        marcado[i] = 0;
    }

    for (auto v = 0; v < num_vertices_; v++) {
        if (marcado[v] == 0) {
            if (!eh_caminho(0, v, marcado)) {
                return false;
            }
        }
    }
    return true;
}

bool Grafo::eh_aciclico() {
    int num_vertices_ = num_vertices();
    int marcado[num_vertices_];
    for (auto i = 0; i < num_vertices_; i++) {
        marcado[i] = 0;
    }

    for (auto v = 0; v < num_vertices_; v++) {
        if (marcado[v] == 0) {
            if (eh_um_grafo_aciclico(v, marcado)) {
                return true;
            }
        }
    }
    return false;
}

bool Grafo::eh_um_grafo_aciclico(int v, int marcado[]) {
    marcado[v] = 1;
    int num_vertices_ = num_vertices();
    for (auto u = 0; u < num_vertices_; u++) {
        if (matriz_adj_[v][u] != 0) {
            if (marcado[u] == 0) {
                if (eh_um_grafo_aciclico(u, marcado)) {
                    return true;
                }
            } else if (marcado[u] == 1) {
                return true;
            }
        }
    }

    marcado[v] = 2;
    return false;
}
