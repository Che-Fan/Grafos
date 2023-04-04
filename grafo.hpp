#ifndef GRAFO_H
#define GRAFO_H

#include <list>

class Grafo 
{
    private:
        int v;
        std::list<int> *adj;
        bool visitado;

    public:
        Grafo();
        void inicia_grafo(int v);
        void add_aresta(int v1, int v2);
        void remove_aresta(int v1, int v2);
        void vertices_adj(int v);
        int grau_vertice(int v);
        void circuito_euleriano(int v);
        void deleta_lista();
};

#endif