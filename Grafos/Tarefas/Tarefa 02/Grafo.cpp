#include "Grafo.h"
#include <iostream>

using namespace std;

Grafo::Grafo(int num_vertices) {
    num_vertices_ = num_vertices; 
    num_arestas_ = 0;
    matriz_adj_.resize(num_vertices);
    for (auto i = 0; i < num_vertices; i++) {
        matriz_adj_[i].resize(num_vertices, 0);
    }
}

int Grafo::num_vertices() {
    return num_vertices_;
}

int Grafo::num_arestas() {
    return num_arestas_;
}

void Grafo::insere_aresta(Aresta e) {
    if ((matriz_adj_[e.v1][e.v2] == 0) && (e.v1 != e.v2)) {
        matriz_adj_[e.v1][e.v2] = 1;
        matriz_adj_[e.v2][e.v1] = 1;
        num_arestas_++;
    }
}

void Grafo::remove_aresta(Aresta e) {
    if (matriz_adj_[e.v1][e.v2] != 0) {
        matriz_adj_[e.v1][e.v2] = 0;
        matriz_adj_[e.v2][e.v1] = 0;
        num_arestas_--;
    }
}

void Grafo::imprime() {
    for (auto i = 0; i < num_vertices_; i++) {
        cout << i << ":";
        for (auto j = 0; j < num_vertices_; j++) {
            if (matriz_adj_[i][j] != 0) {
                cout << " " << j;
            }
        }
        cout << "\n";
    }
}

bool Grafo::eh_caminho(vector<int> sequencia) {
    int n = sequencia.size();
    if (n < 2) {
        return true;
    }

    vector<int> marcado(num_vertices_, 0);

    for (int i = 0; i < n - 1; i++) {
        int v = sequencia[i];
        int w = sequencia[i + 1];

        // Verifica se a aresta entre v e w existe e não foi percorrida anteriormente
        if (matriz_adj_[v][w] == 0 || marcado[v] == 1) {
            return false;
        }

        marcado[v] = 1; // Marca o vértice como visitado após cada verificação de caminho
    }

    // Verifica se o último vértice da sequência não foi percorrido anteriormente
    int ultimo_vertice = sequencia[n - 1];
    if (marcado[ultimo_vertice] == 1) {
        return false;
    }

    return true;
}

bool Grafo::caminho(int v, int w, int marcado[]) {
    if (v == w) {
        return true;
    }
    marcado[v] = 1;
    for (auto u = 0; u < num_vertices_; u++) {
        if (matriz_adj_[v][u] != 0) {
            if (marcado[u] == 0) {
                if (caminho(u, w, marcado)) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool Grafo::existe_caminho(int v, int w) {
    int num_vertices_ = num_vertices();
    int marcado[num_vertices_];
    for (auto i = 0; i < num_vertices_; i++) {
        marcado[i] = 0;
    }
    return caminho(v, w, marcado);
}

bool Grafo::eh_conexo() {
    int num_vertices_ = num_vertices();

    // Verifica se há pelo menos um vértice no grafo
    if (num_vertices_ <= 0) {
        return false;
    }

    // Escolhe um vértice inicial para começar a busca por componentes conexas
    int vertice_inicial = 0;

    // Percorre todos os vértices a partir do vértice inicial
    for (int i = 0; i < num_vertices_; i++) {
        if (!existe_caminho(vertice_inicial, i)) {
            // Se não houver caminho entre o vértice inicial e algum outro vértice, o grafo é desconexo
            return false;
        }
    }

    return true;
}

// bool Grafo::eh_aciclico() {
//     int num_vertices_ = num_vertices();

//     // Verifica se o grafo está vazio
//     if (num_vertices_ <= 0) {
//         return true;
//     }

//     // Percorre todos os vértices do grafo
//     for (int v = 0; v < num_vertices_; v++) {
//         int marcado[num_vertices_];
//         for (int i = 0; i < num_vertices_; i++) {
//             marcado[i] = 0;
//         }

//         // Verifica se o vértice atual está em um grafo acíclico
//         if (eh_um_grafo_aciclico(v, marcado)) {
//             return false;
//         }
//     }

//     return true;
// }
bool Grafo::eh_aciclico() {
    // Verifica se o grafo está vazio
    if (num_vertices_ <= 0 || num_arestas_ <= 2) {
        return true;
    }

    // Percorre todos os vértices do grafo
    for (int v = 0; v < num_vertices_; v++) {
        int w = v;
        int marcado[num_vertices_];
        for (int i = 0; i < num_vertices_; i++) {
            marcado[i] = 0;
        }

        // Verifica se o vértice atual está em um grafo acíclico
        if (!eh_um_grafo_aciclico(v, w, marcado)) {
            return false;
        }
    }

    return true;
}

// bool Grafo::eh_um_grafo_aciclico(int v, int marcado[]) {
//     marcado[v] = 1;

//     for (int u = 0; u < num_vertices_; u++) {
//         if (matriz_adj_[v][u] != 0) {
//             if (marcado[u] == 0) {
//                 // Verifica se há um ciclo
//                 if (!eh_um_grafo_aciclico(u, marcado)) {
//                     cout << "kkkkkkkkkk";
//                     return false;
//                 }
//             } else if (marcado[u] == 1) {
//                 // Encontrou um ciclo
//                 return true;
//             }
//         }
//     }

//     marcado[v] = 2;
//     return false;
// }
bool Grafo::eh_um_grafo_aciclico(int v, int w, int marcado[]) {
    marcado[v] = 1;
    int cont = 0;
    for (auto u = 0; u < num_vertices_; u++) {
        if (matriz_adj_[v][u] != 0) {
            if (marcado[u] == 0) {
                if (caminho(u, w, marcado)) {
                    cont += 1;
                }
            } else if (marcado[u] == 1) {
                // Encontrou um ciclo
                return false;
            }
        }
    }
    // cout << "Contador: " << cont << "\n";
    // if (cont > 1){
    //     return false;
    // } else {
    //     return true;
    // }
    return true;
}

