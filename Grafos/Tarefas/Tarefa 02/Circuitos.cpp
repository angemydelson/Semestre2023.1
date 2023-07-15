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
    int V, E;
    cin >> V >> E;

    Grafo grafo(V);

    for (int i = 0; i < E; i++) {
        int X, Y;
        cin >> X >> Y;
        Aresta aresta = {X, Y};
        grafo.insere_aresta(aresta);
    }

    int O;
    cin >> O;

    for (int i = 0; i < O; i++) {
        char op;
        cin >> op;

        if (op == 'S') {
            int N;
            cin >> N;
            vector<int> sequencia(N);
            for (int j = 0; j < N; j++) {
                cin >> sequencia[j];
            }
            if (grafo.eh_caminho(sequencia)) {
                cout << "SIM" << endl;
            } else {cout << "NAO" << endl;
        }
    } else if (op == 'C') {
        int X, Y;
        cin >> X >> Y;
        if (grafo.existe_caminho(X, Y)) {
            cout << "SIM" << endl;
        } else {
            cout << "NAO" << endl;
        }
    } else if (op == 'X') {
        if (grafo.eh_conexo()) {
            cout << "SIM" << endl;
        } else {
            cout << "NAO" << endl;
        }
    } else if (op == 'A') {
        if (grafo.eh_aciclico()) {
            cout << "SIM" << endl;
        } else {
            cout << "NAO" << endl;
        }
    }
    }

    return 0;
}