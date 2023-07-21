/*
 * Tarefa 03 - Viacao Grafeira
 *
 * GEN254 - Grafos - 2023/1
 *
 * Nome:      XXXX
 * Matricula: XXXX
 */

#ifndef DIGRAFO_H

#define DIGRAFO_H

#include "Aresta.h"
#include <vector>
#include <list>
#include <utility>

class Digrafo {
public:
    /** Constroi um digrafo simples que possui o numero de vertices recebido
     *  por parametro e que nao possui arestas
     */
    Digrafo(int num_vertices);

    int num_vertices();
    int num_arestas();

    bool tem_aresta(Aresta e);

    /** Insere uma aresta no grafo caso a aresta ainda nao exista no grafo e
     * nao seja um laco
     */
    void insere_aresta(Aresta e);

    /** Remove uma aresta do grafo caso a aresta exista no grafo */
    void remove_aresta(Aresta e);

    void dijkstra(int v, std::vector<int> &pai, std::vector<int> &dist_pond);

    void imprime_caminhos_viaveis_arv(int v, std::vector<int> &pai,
        std::vector<int> &dist_pond, int dist_min);


    void imprime_caminhos_viaveis(int v, int dist_min);

    void imprime();
private:
    int num_vertices_;
    int num_arestas_;
    std::vector<std::list<std::pair<int,int>>> listas_adj_;

    void valida_vertice(int v);
    void valida_aresta(Aresta e);
};

#endif /* DIGRAFO_H */
