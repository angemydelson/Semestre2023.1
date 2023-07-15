/*
 * Tarefa 03 - Viacao Grafeira
 *
 * GEN254 - Grafos - 2023/1
 *
 * Nome:      Angemydelson Saint Bert
 * Matricula: 2121101002
 */

/* Complete aqui */

#ifndef GRAFO_H

#define GRAFO_H

#include "Aresta.h"
#include <vector>
#include <list>


class Digrafo {
public:
    Digrafo(int num_vertices);
    int num_vertices();
    int num_arestas();
    void insere_aresta(Aresta e);
    void remove_aresta(Aresta e);
    void imprime();
    int grau(int vertice);
    int grauMinimo();
    int grauMaximo();
    bool existe_aresta(Aresta e);
    std::vector<int> dijkstra(int origem, std::vector<int>& pai);
    void reavaliarCidades(int origemCidade, int minimaExtensao);
private:
    int num_vertices_;
    int num_arestas_;
    std::vector<std::list<Aresta>> lista_adj_;
};


#endif /* GRAFO_H */
