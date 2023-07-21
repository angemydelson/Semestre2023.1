/*
 * Tarefa 03 - Viacao Grafeira
 *
 * GEN254 - Grafos - 2023/1
 *
 * Nome:      XXXX
 * Matricula: XXXX
 */

#include "Aresta.h"
#include "Digrafo.h"
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
        int C;
        int T;
        int X;
        int Y;
        int Z;
        int R;
        int M;
    
        cin >> C >> T;
    
        Digrafo g(C);
    
        for (int i = 0; i < T; i++) {
            cin >> X >> Y >> Z;
            g.insere_aresta(Aresta(X, Y, Z));
        }
    
        cin >> R;
    
        for (int i = 0; i < R; i++) {
            cin >> X >> M;
            g.imprime_caminhos_viaveis(X, M);

            cout << "\n";
        }
    }
    catch (const exception &e) {
        print_exception(e);
    }

    return 0;
}
