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

bool Grafo::eh_caminho(Aresta e, int marcado[]){
    if (e.v1 == e.v2){
        cout << e.v1 <<"-";
        return true;
    }
    marcado[e.v1] = 1;
    for( auto u = 0; u < num_vertices_; u++){
        if (matriz_adj_[e.v1][e.v2] != 0){
            if (marcado[u] == 0){
                if (eh_caminho(e.v1, e.v2, marcado)){
                    cout << e.v1 <<"-";
                    return true;
                }
            } 
        }
    }
    return false;
}