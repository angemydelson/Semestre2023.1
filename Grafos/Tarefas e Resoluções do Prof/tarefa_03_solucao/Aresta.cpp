/*
 * Tarefa 03 - Viacao Grafeira
 *
 * GEN254 - Grafos - 2023/1
 *
 * Nome:      XXXX
 * Matricula: XXXX
 */

#include "Aresta.h"
#include <string>

Aresta::Aresta(int v1, int v2) : v1(v1), v2(v2), peso(0) {
}

Aresta::Aresta(int v1, int v2, int peso) : v1(v1), v2(v2), peso(peso) {
}

std::string Aresta::to_string() {
    return std::to_string(v1) + " " + std::to_string(v2);
}
