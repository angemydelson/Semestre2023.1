#include "Aresta.h"
#include <vector>

class Grafo {
public:
    Grafo(int num_vertices);
    int num_vertices();
    int num_arestas();
    void insere_aresta(Aresta e);
    void remove_aresta(Aresta e);
    void imprime();
    bool eh_caminho(Aresta e, int marcado[]);
    bool existe_caminho();
    bool eh_conexo();
    bool eh_aciclico();
private:
    int num_vertices_;
    int num_arestas_;
    std::vector<std::vector<int>> matriz_adj_;
};