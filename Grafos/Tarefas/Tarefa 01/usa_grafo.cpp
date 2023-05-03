/*
 * Tarefa 01 - Grafo - Listas de Adjacencia
 *
 * GEN254 - Grafos - 2023/1
 *
 * Nome:      Angemydelson Saint Bert
 * Matricula: 2121101002
 */
#include "Grafo.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    /* Complete aqui */
    
    

    int V, O;
    string input;
    cin >> V >> O;
    Grafo g(V);
    for (auto i = 0; i < O; i++){
        cin >> input;
        if (input == "I"){
            int v1, v2;
            cin >> v1 >> v2;
            Aresta e(v1,v2);
            g.insere_aresta(e);
        } else if (input == "R"){
            int v1, v2;
            cin >> v1 >> v2;
            Aresta e(v1,v2);
            g.remove_aresta(e);
        } else if (input == "E"){
            g.num_arestas();
            cout << g.num_arestas();
        } else if (input == "X"){
            g.grau_maximo();
            cout << g.grau_maximo() << "\n";
        } else if (input == "N"){
            g.grau_minimo();
            cout << g.grau_minimo() << "\n";
        } else if (input == "P"){
            g.imprime();
        }
    }


    return 0;
}
