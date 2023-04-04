#include <iostream>
#include <string>
#include <fstream>
#include <utility>
#include <vector>
#include "grafo.hpp"

using  namespace std;

// Nome: Che Fan Pan
// NUSP: 1120042
// Turma B

int main()
{

    string nome_arquivo;
    cin >> nome_arquivo;

    // Leitura do nome do arquivo de entrada
    ifstream arquivo(nome_arquivo);
    if(!arquivo.is_open()){ // Teste de erro
        cout << "Erro ao abrir o arquivo." << endl;
        return 0;
    }

    int num_vertices, num_arestas, v1, v2;
    // Instanciando o grafo
    Grafo *grafo = new Grafo();

    while(arquivo >> num_vertices){

        grafo->inicia_grafo(num_vertices);

        arquivo >> num_arestas;

        // Leitura dos pares de vértices que formam uma aresta
        int n = num_arestas;
        while(n--){
            arquivo >> v1;
            arquivo >> v2;
            grafo->add_aresta(v1, v2);
        }
    }

    bool euleriano = true;
    for(int i = 0; i < num_vertices; i++)
    {
        int grau;
        grau = grafo->grau_vertice(i);

        // Se o grau do vértice for ímpar, não há ciclo euleriano
        if(grau%2 != 0){
            cout << "Não" << endl;
            euleriano = false;
            break;
        }
    }

    if(euleriano){
        cout << "Sim" << endl;
        grafo->circuito_euleriano(0);
    }
    
    arquivo.close();
    grafo->deleta_lista();
    delete grafo;

    return 0;
}