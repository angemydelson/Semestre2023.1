/*
 * Tarefa 01 - Grafo - Listas de Adjacencia
 *
 * GEN254 - Grafos - 2023/1
 *
 * Nome:      XXXX
 * Matricula: XXXX
 */

#include "Aresta.h"
#include "Grafo.h"
#include <exception>
#include <string>
#include <iostream>

using namespace std;

void print_exception(const exception &e, int level = 0) {
    cerr << "exception: " << string(level, ' ') << e.what() << "\n";
    try {
        rethrow_if_nested(e);
    } catch(const std::exception& nested_exception) {
        print_exception(nested_exception, (level + 2));
    }
}

int main() {
    try {
        int V;
        int O;
        char op;
        int v1;
        int v2;

        cin >> V >> O;

        Grafo g(V);

        for (int i = 0; i < O; i++) {
            cin >> op;

            switch (op) {
                case 'I':
                    cin >> v1 >> v2;
                    g.insere_aresta(Aresta(v1, v2));
                    break;
    
                case 'R':
                    cin >> v1 >> v2;
                    g.remove_aresta(Aresta(v1, v2));
                    break;
    
                case 'E':
                    cout << g.num_arestas() << endl;
                    break;
    
                case 'X':
                    cout << g.grau_maximo() << endl;
                    break;
    
                case 'N':
                    cout << g.grau_minimo() << endl;
                    break;
    
                case 'P':
                    g.imprime();
                    break;
    
                default:
                    throw(runtime_error("Erro na funcao main: a operacao "
                        + to_string(op) + " eh invalida!"));
            }
        }
    }
    catch (const exception &e) {
        print_exception(e);
    }

    return 0;
}
