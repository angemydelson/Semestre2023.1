/*
 * Tarefa 03 - Viacao Grafeira
 *
 * GEN254 - Grafos - 2023/1
 *
 * Nome:      Angemydelson Saint Bert
 * Matricula: 2121101002
 */

#include "Digrafo.h"
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int cityCount, edgeCount;
    cin >> cityCount >> edgeCount;

    Digrafo graph(cityCount);

    int i = 0;
    while (i < edgeCount) {
        int originCity, destinationCity, extension;
        cin >> originCity >> destinationCity >> extension;
        graph.insere_aresta(Aresta(originCity, destinationCity, extension));
        i++;
    }

    int reevaluationCount;
    cin >> reevaluationCount;

    int j = 0;
    while (j < reevaluationCount) {
        int originCity, minimumExtension;
        cin >> originCity >> minimumExtension;
        graph.reavaliarCidades(originCity, minimumExtension);
        j++;
    }

    return 0;
}
