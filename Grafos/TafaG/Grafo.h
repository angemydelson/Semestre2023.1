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
    bool eh_caminho(std::vector<int> sequencia);
    bool caminho(int v, int w, int marcado[]);
    bool existe_caminho(int v, int w);
    bool eh_conexo();
    bool eh_aciclico();
    bool eh_um_grafo_aciclico(int v, int marcado[]);
private:
    int num_vertices_;
    int num_arestas_;
    // std::vector<int> marcado_;
    std::vector<std::vector<int>> matriz_adj_;
};