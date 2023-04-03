/*
 * Tarefa 01 - Grafo - Listas de Adjacencia
 *
 * GEN254 - Grafos - 2023/1
 *
 * Nome:      XXXX
 * Matricula: XXXX
 */

#ifndef GRAFO_H

#define GRAFO_H

#include "Aresta.h"

class Grafo {
public:
    Grafo(int num_vertices);
    // ~Grafo(); // Se necessario
    int num_arestas();
    void insere_aresta(Aresta e);
    void remove_aresta(Aresta e);
    int grau_maximo();
    int grau_minimo();
    void imprime();
private:
    int num_vertices_;
    int num_arestas_;
};

#endif /* GRAFO_H */
