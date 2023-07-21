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
#include <vector>
#include <list>

class Grafo {
public:
    /** Constroi um grafo simples que possui o numero de vertices recebido por
     *  parametro e que nao possui arestas
     */
    Grafo(int num_vertices);

    int num_vertices();
    int num_arestas();

    bool tem_aresta(Aresta e);

    /** Insere uma aresta no grafo caso a aresta ainda nao exista no grafo e
     * nao seja um laco
     */
    void insere_aresta(Aresta e);

    /** Remove uma aresta do grafo caso a aresta exista no grafo */
    void remove_aresta(Aresta e);

    int grau(int v);
    int grau_maximo();
    int grau_minimo();

    void imprime();
private:
    int num_vertices_;
    int num_arestas_;
    std::vector<std::list<int>> listas_adj_;

    void valida_vertice(int v);
    void valida_aresta(Aresta e);
};

#endif /* GRAFO_H */
