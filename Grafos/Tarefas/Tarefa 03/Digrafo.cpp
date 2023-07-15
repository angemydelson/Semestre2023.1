/*
 * Tarefa 03 - Viacao Grafeira
 *
 * GEN254 - Grafos - 2023/1
 *
 * Nome:      Angemydelson Saint Bert
 * Matricula: 2121101002
 */

/* Complete aqui */

#include "Digrafo.h"
#include <iostream>
#include "Filapri_min.h"
#include <vector>
#include <limits>

using namespace std;

Digrafo::Digrafo(int num_vertices) {
    num_vertices_ = num_vertices; 
    num_arestas_ = 0;
    lista_adj_.resize(num_vertices);  
}

int Digrafo::num_vertices() {
    return num_vertices_;
}

int Digrafo::num_arestas() {
    return num_arestas_;
}


void Digrafo::insere_aresta(Aresta e){
    if(existe_aresta(e) || e.v1 == e.v2) return;
    lista_adj_[e.v1].push_front(e);
    num_arestas_++;    
}

void Digrafo::remove_aresta(Aresta e){
    if(!existe_aresta(e)) return;
    lista_adj_[e.v1].remove(e);
    num_arestas_--;  
}


void Digrafo::imprime() {
    int i = 0;
    while (i < num_vertices_) {
        cout << i << ": ";
        auto it = lista_adj_[i].begin();
        while (it != lista_adj_[i].end()) {
            cout << "(" << it->v2 << "," << it->peso << ") ";
            it++;
        }
        cout << endl;
        i++;
    }
}

int Digrafo::grau(int vertice) {
    return lista_adj_[vertice].size();
}

int Digrafo::grauMinimo() {
    int grauMinimo = grau(0);
    int i = 1;
    while (i < num_vertices_) {
        if (grau(i) < grauMinimo) {
            grauMinimo = grau(i);
        }
        i++;
    }
    return grauMinimo;
}

int Digrafo::grauMaximo() {
    int grauMaximo = grau(0);
    int i = 1;
    while (i < num_vertices_) {
        if (grau(i) > grauMaximo) {
            grauMaximo = grau(i);
        }
        i++;
    }
    return grauMaximo;
}

bool Digrafo::existe_aresta(Aresta aresta) {
    int v1 = aresta.v1;
    for (auto it = lista_adj_[v1].begin(); it != lista_adj_[v1].end(); ++it) {
        if (it->v2 == aresta.v2) {
            return true;
        }
    }
    return false;
}

const int INF = std::numeric_limits<int>::max();

vector<int> Digrafo::dijkstra(int origem, vector<int>& pai) {
    int n = num_vertices_;

    vector<int> dp(n, INF);

    dp[origem] = 0;

    Filapri_min<int> pq(n);

    int i = 0;
    while (i < n) {
        pq.insere(i, dp[i]);
        i++;
    }

    while (!pq.vazia()) {
        auto item = pq.remove();
        int u = item.first;
        int dpU = item.second;

        if (dpU != dp[u] || dp[u] == INF) {
            continue;
        }

        auto vizinho = lista_adj_[u].begin();
        while (vizinho != lista_adj_[u].end()) {
            int v = vizinho->v2;
            int peso = vizinho->peso;

            if (dp[v] > dp[u] + peso) {
                dp[v] = dp[u] + peso;
                pai[v] = u;
                pq.diminui_prio(v, dp[v]);
            }

            vizinho++;
        }
    }

    return dp;
}

void printCaminho(const vector<int>& pai, int destino) {
    vector<int> caminho;
    int verticeAtual = destino;

    while (verticeAtual != -1) {
        caminho.push_back(verticeAtual);
        verticeAtual = pai[verticeAtual];
    }

    int i = 0;
    while (i < (int) caminho.size()) {
        std::cout << caminho[i] << " ";
        i++;
    }
}

void Digrafo::reavaliarCidades(int origemCidade, int minimaExtensao) {
    int numCidades = num_vertices_;
    vector<int> pai(num_vertices_, -1);
    vector<int> distancia = dijkstra(origemCidade, pai);
   
    
    for (int currentCity = 0; currentCity < numCidades; currentCity++) {
        
        if (currentCity == origemCidade)
            continue;

        cout << currentCity << ": ";

        if (distancia[currentCity] >= minimaExtensao && distancia[currentCity] != INF){
            cout << distancia[currentCity] << ", ";

            int currentVertex = currentCity;

            while (currentVertex != origemCidade) {
                int previousVertex = currentVertex;
                auto edge = lista_adj_[currentVertex].begin();
                while (edge != lista_adj_[currentVertex].end()) {
                    int nextVertex = edge->v2;
                    int peso = edge->peso;

                    if (distancia[currentVertex] - peso == distancia[nextVertex]) {
                        currentVertex = nextVertex;
                        break;
                    }

                    edge++;
                }
                if (previousVertex == currentVertex) break;
            }
            printCaminho(pai, currentCity);

        } else {
            cout << "economicamente inviavel partindo de " << origemCidade;
        }

        cout << endl;
        
    }

    cout << endl;
}

