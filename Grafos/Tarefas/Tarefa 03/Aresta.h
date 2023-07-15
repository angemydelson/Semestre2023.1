/*
 * Tarefa 03 - Viacao Grafeira
 *
 * GEN254 - Grafos - 2023/1
 *
 * Nome:      Angemydelson Saint Bert
 * Matricula: 2121101002
 */

class Aresta {
public:
    const int v1;
    const int v2;
    int peso;
    Aresta(int v1, int v2, int peso);
        // Equality operator
    bool operator==(const Aresta& other) const {
        return (v1 == other.v1) && (v2 == other.v2);
    }
};
