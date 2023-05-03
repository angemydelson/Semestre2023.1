/*
 * Tarefa 01 - Grafo - Listas de Adjacencia
 *
 * GEN254 - Grafos - 2023/1
 *
 * Nome:      Angemydelson Saint Bert
 * Matricula: 2121101002
 */

#ifndef GRAFO_H

#define GRAFO_H

#include "Aresta.h"
#include <list>
#include <vector>


class Grafo {
    public:
        Grafo(int num_vertices);
        // ~Grafo(); // Se necessario
        int num_vertices();
        int num_arestas();
        void insere_aresta(Aresta e);
        void remove_aresta(Aresta e);
        int grau_maximo();
        int grau_minimo();
        void imprime();
        std::vector<std::list<int>> lista_adj_;
        bool existe_aresta(Aresta e);
    private:
        int num_vertices_;
        int num_arestas_;
};

#endif /* GRAFO_H */
