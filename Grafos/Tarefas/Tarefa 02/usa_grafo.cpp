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
    
    

    int V, O;
    string input;
    cin >> V >> O;
    Grafo g(V);
    for (auto j = 0; j < V; j++ ){
            int v1, v2;
            cin >> v1 >> v2;
            Aresta e(v1,v2);
            g.insere_aresta(e);
    }
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
            int cont = 0;
            for (auto k= 0; k < N; k++){
                int marcado[N];
                if (k > 0) {
                    if ((g.eh_caminho(guardando[k-1], guardando[k], marcado)) == true){
                        cont = 1; 
                    } else {
                        cout << "NAO";
                        break;
                    };
                }
            }
            if (cont == 1){
                cout << "SIM";
            }
            // int v1, v2;
            // cin >> v1 >> v2;
            // Aresta e(v1,v2);
            // g.insere_aresta(e);
        } else if (input == "X"){
            if (g.eh_conexo() == false){
                cout << "NAO";
            } else {
                cout <<"SIM";
            };
            
        } else if (input == "A"){
            if (g.eh_aciclico() == false){
                cout << "NAO";
            } else {
                cout <<"SIM";
            };
        } else if (input == "X"){
            int X, Y;
            cin >> X >> Y;
            bool verificao = g.existe_caminho(X,Y);
            if (verificao == true){
                cout << "SIM";
            } else {
                cout << "NAO";
            }
        } 
    }


    return 0;
}

// int main() {

//     /* Complete aqui */
    
    

//     int V, E, O;
//     string input;
//     cin >> V >> O;
//     Grafo g(V);
//     for (auto i = 0; i < O; i++){
//         cin >> input;
//         if (input == "I"){
//             int v1, v2;
//             cin >> v1 >> v2;
//             Aresta e(v1,v2);
//             g.insere_aresta(e);
//         } else if (input == "R"){
//             int v1, v2;
//             cin >> v1 >> v2;
//             Aresta e(v1,v2);
//             g.remove_aresta(e);
//         } else if (input == "E"){
//             g.num_arestas();
//             cout << g.num_arestas();
//         } else if (input == "X"){
//             int vvv, vv;
//             int marcado_[20];
//             cin>> vvv >> vv;
//             g.eh_caminho(vv, vvv, marcado_);
//             cout << g.eh_caminho(vv, vvv, marcado_) << "\n";
//         } 
//             else if (input == "P"){
//             g.imprime();
//         }
//     }


//     return 0;
// }