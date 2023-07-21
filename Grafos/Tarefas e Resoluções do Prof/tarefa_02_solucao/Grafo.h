/*
 * Tarefa 02 - Testes em Circuitos Integrados
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

class Grafo {
public:
    /** Constroi um grafo simples que possui o numero de vertices recebido por
     *  parametro e que nao possui arestas
     */
    Grafo(int num_vertices);

    int num_vertices();
    int num_arestas();

    /** Insere uma aresta no grafo caso a aresta ainda nao exista no grafo e
     * nao seja um laco
     */
    void insere_aresta(Aresta e);

    /** Remove uma aresta do grafo caso a aresta exista no grafo */
    void remove_aresta(Aresta e);

    bool eh_caminho(std::vector<int> &seq_vertices);
    bool existe_caminho(int v, int w);
    bool eh_conexo();
    bool eh_aciclico();

    void imprime();
private:
    int num_vertices_;
    int num_arestas_;
    std::vector<std::vector<int>> matriz_adj_;

    bool existe_caminho_rec(int v, int w, std::vector<int> &marcado);
    void valida_vertice(int v);
    void valida_aresta(Aresta e);
};

#endif /* GRAFO_H */
