/*
 * Tarefa 02 - Testes em Circuitos Integrados
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
#include <vector>

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
        int E;
        int v1;
        int v2;
        int O;
        char op;
        int N;

        cin >> V >> E;

        Grafo g(V);

        for (int i = 0; i < E; i++) {
            cin >> v1 >> v2;
            g.insere_aresta(Aresta(v1, v2));
        }

        vector<int> seq_vertices;

        cin >> O;

        for (int i = 0; i < O; i++) {
            cin >> op;

            switch (op) {
                case 'S':
                    cin >> N;

                    seq_vertices.resize(N);
                    for (int j = 0; j < N; j++) {
                        cin >> seq_vertices[j];
                    }

                    cout << (g.eh_caminho(seq_vertices) ? "SIM" : "NAO")
                        << endl;

                    break;
    
                case 'C':
                    cin >> v1 >> v2;

                    cout << (g.existe_caminho(v1, v2) ? "SIM" : "NAO") << endl;

                    break;
    
                case 'X':
                    cout << (g.eh_conexo() ? "SIM" : "NAO") << endl;

                    break;
    
                case 'A':
                    cout << (g.eh_aciclico() ? "SIM" : "NAO") << endl;

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
