/*
 * Tarefa 03 - Viacao Grafeira
 *
 * GEN254 - Grafos - 2023/1
 *
 * Nome:      Angemydelson Saint Bert
 * Matricula: 2121101002
 */

/* Complete aqui */

#include "Aresta.h"

Aresta::Aresta(int v1, int v2, int peso) : v1(v1), v2(v2), peso(peso) {
}

bool operator==(const Aresta& a1, const Aresta& a2) {
    return (a1.v1 == a2.v1) && (a1.v2 == a2.v2);
}

