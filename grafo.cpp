#include <iostream>
#include <string>
#include <fstream>
#include <utility>
#include <vector>
#include <list>
#include "grafo.hpp"

using namespace std;

Grafo::Grafo(){

}

void Grafo::inicia_grafo(int v){
    this->v = v;
    adj = new list<int>[v]; // Aloca um vetor de lista com tamanho v vértices
}

void Grafo::add_aresta(int v1, int v2){
    adj[v1].push_back(v2);
    adj[v2].push_back(v1);
}

void Grafo::remove_aresta(int v1, int v2){
    adj[v1].remove(v2);
    adj[v2].remove(v1);
}

void Grafo::vertices_adj(int v){
    for(list<int>::iterator i = adj[v].begin(); i != adj[v].end(); i++){
        cout << *i << " " ;
    }
}

int Grafo::grau_vertice(int v){
    int grau = 0;
    for(list<int>::iterator i = adj[v].begin(); i != adj[v].end(); i++){
        grau++;
    }
    return grau;
}

void Grafo::circuito_euleriano(int v1){
    int grau_v1, grau_v0, v2;
    grau_v0 = grau_vertice(0);
    grau_v1 = grau_vertice(v1);

    if(grau_v1 >= 1){
        cout << v1 << " ";
        v2 = adj[v1].front();
        if(v2 != 0 || (v2 == 0 && grau_v0 > 1 && grau_v1 > 1) || (v2 == 0 && grau_v1 == 1)){
            remove_aresta(v1,v2);
            circuito_euleriano(v2);
        }
        else if(v2 == 0 && grau_v0 == 1 && grau_v1 > 1){
            list<int>::iterator front = adj[v1].begin();
            advance(front, 1);
            v2 = *front;
            remove_aresta(v1,v2);
            circuito_euleriano(v2);
        }
    }
    else{
        cout << v1;
        return;
    }      
}

void Grafo::deleta_lista(){
    delete [] adj;
}
