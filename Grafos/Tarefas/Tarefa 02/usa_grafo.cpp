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

    /* Complete aqui */
    
    

    int V, E, O;
    string input;
    cin >> V >> E;
    Grafo g(V);
    for (auto j = 0; j < E; j++ ){
            int v1, v2;
            cin >> v1 >> v2;
            Aresta e(v1,v2);
            g.insere_aresta(e);
    }
    cin >> O;
    for (auto i = 0; i < O; i++){
        
        cin >> input;

        if (input == "S"){
            int N;
            cin >> N;
            int guardando[N];
            for (auto j = 0; j < N; j++){
                int n;
                cin >> n;
                guardando[j] = n;
            }
            if (g.eh_caminho(N, guardando) == false){
                cout << "NAO" << "\n";
            } else {
                cout <<"SIM" << "\n";
            }
            
        } else if (input == "X"){
            if (g.eh_conexo() == false){
                cout << "NAO" << "\n";
            } else {
                cout <<"SIM" << "\n";
            };
            
        } else if (input == "A"){
            if (g.eh_aciclico() == false){
                cout << "NAO" << "\n";
            } else {
                cout <<"SIM" << "\n";
            };
        } else if (input == "C"){
            int X, Y;
            cin >> X >> Y;
            bool verificao = g.existe_caminho(X,Y);
            if (verificao == true){
                cout << "SIM" <<"\n";
            } else {
                cout << "NAO" << "\n";
            }
        } 
    }
    return 0;
}