
/*
    Olimpíada Brasileira de Informática
    Nível 2, Fase 2, 2011
    Problema: Reduzindo detalhes de um mapa
    
    Data de submissão: 30/03/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: union-find, conjuntos-disjuntos, grafos, arvore-menor-caminho, 
        algoritmo-kruskal
    Complexidade: O(M log N)
*/

#include <iostream>
#include <cstdio>
#include <list>
#include <algorithm>
using namespace std;

struct Node {
    int parent, rank;
};

void makeSet(Node nodes[], int length) {
    for (int i = 0; i < length; i++) {
        nodes[i].parent = i;
        nodes[i].rank = 0;
    }
}

void link(Node nodes[], int x, int y) {
    if ( nodes[x].rank > nodes[y].rank ) {
        nodes[y].parent = x;
    } else {
        nodes[x].parent = y;
        if ( nodes[x].rank == nodes[y].rank ) 
            nodes[y].rank++;
    }
}

int find(Node nodes[], int x) {
    if ( x != nodes[x].parent ) 
        nodes[x].parent = find(nodes, nodes[x].parent);
    return nodes[x].parent;
}

void unify(Node nodes[], int x, int y) {
    link(nodes, find(nodes, x), find(nodes, y));
}

struct Edge {
    int c, u, v;
    
    Edge(int c, int u, int v) {
        this->c = c;
        this->u = u;
        this->v = v;
    }
};

bool comp(Edge e, Edge f) {
    return e.c < f.c;
}

int main() {
    
    Node nodes[500];
    list<Edge> edges;
    int ncidades, nrodovias, c, u, v, soma = 0;
    
    scanf("%d%d", &ncidades, &nrodovias);
    
    makeSet(nodes, ncidades);
    
    for (int i = 0; i < nrodovias; i++) {
        scanf("%d%d%d", &u, &v, &c);
        u--; v--;
        edges.push_back(Edge(c, u, v));
    }
    
    edges.sort(comp);
    
    for (list<Edge>::iterator it = edges.begin(); it != edges.end(); it++) {
        if ( find(nodes, it->u) != find(nodes, it->v) ) {
            unify(nodes, it->u, it->v);
            soma += it->c;
        }
    }
    
    printf("%d", soma);

    return 0;
}
