/*
 * Tarefa 01 - Grafo - Listas de Adjacencia
 *
 * GEN254 - Grafos - 2023/1
 *
 * Nome:      Angemydelson Saint-Bert
 * Matricula: 2121101002
 */

/* Complete aqui */

#include "Grafo.h"
#include <iostream>
#include <list>

using namespace std;

Grafo::Grafo(int num_vertices) {
    num_vertices_ = num_vertices; 
    num_arestas_ = 0;
    lista_adj_.resize(num_vertices);
}

int Grafo::num_vertices() {
    return num_vertices_;
}

int Grafo::num_arestas() {
    return num_arestas_;
}

void Grafo::insere_aresta(Aresta e) {
    if ((e.v1 != e.v2) && (!existe_aresta(e))) {
        lista_adj_[e.v1].push_front(e.v2);
        lista_adj_[e.v2].push_front(e.v1);
        num_arestas_++;
    }
}

void Grafo::remove_aresta(Aresta e) {
    if (existe_aresta(e)) {
        lista_adj_[e.v1].remove(e.v2);
        lista_adj_[e.v2].remove(e.v1);
        num_arestas_--;
    }
}

void Grafo::imprime() {
    for (auto i = 0; i < num_vertices_; i++) {
        cout << i << ":";
        for (auto j : lista_adj_[i]) {
            cout << " " << j;
        }
        cout << "\n";
    }
}

bool Grafo::existe_aresta(Aresta e) {
    for (auto j : lista_adj_[e.v1]) {
        if (j == e.v2) {
            return true;
        }
    }
    return false;
}

int Grafo::grau_maximo() {
    int grau_max = 0;
    int grau;
    for (auto i = 0; i < num_vertices_; i++) {
        grau = lista_adj_[i].size();
        if (grau > grau_max) {
            grau_max = grau;
        }
    }
    return grau_max;
}

int Grafo::grau_minimo() {
    int grau_min = num_vertices_; 
    int grau;
    for (auto i = 0; i < num_vertices_; i++) {
        grau = lista_adj_[i].size();
        if (grau < grau_min) {
            grau_min = grau;
        }
    }
    return grau_min;
}