
/*
    Olimpíada Brasileira de Informática
    Nível 2, Fase 2, 2008
    Problema: Frete da Família Silva
    
    Data de submissão: 29/03/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: union-find, conjuntos-disjuntos, grafos, algoritmos-gulosos, 
        arvore-custo-minimo, algoritmo-kruskal
    Complexidade: O(M log M)
*/

#include <cstdio>
#include <list>
using namespace std;

struct Node {
    int parent, rank;
};

struct ForestTree {
    Node nodes[1000];
    int length;
    
    ForestTree(int len) {
        length = len;
        
        for (int i = 0; i < length; i++) {
            nodes[i].parent = i;
            nodes[i].rank = 0;
        }
    }
    
    int find(int u) {
        if ( u != nodes[u].parent ) 
            nodes[u].parent = find(nodes[u].parent);
        return nodes[u].parent;
    }
    
    void link(int u, int v) {
        if ( nodes[u].rank > nodes[v].rank ) 
            nodes[v].parent = u;
        else {
            nodes[u].parent = v;
            if ( nodes[u].rank == nodes[v].rank ) 
                nodes[v].rank++;
        }
    }
};

struct Edge {
    int u, v, c;
    
    Edge(int u, int v, int c) {
        this->u = u;
        this->v = v;
        this->c = c;
    }
    
    bool operator<(Edge b) {
        return c < b.c;
    }
};

int main() {
    
    int n, m, u, v, c, soma = 0;
    list<Edge> edges;
    
    scanf("%d%d", &n, &m);
    
    ForestTree forest = n;
    
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &c);
        edges.push_back(Edge(u, v, c));
    }
    
    edges.sort();
    
    for (list<Edge>::iterator it = edges.begin(); it != edges.end(); it++) {
        u = forest.find(it->u);
        v = forest.find(it->v);
        
        if ( u != v ) {
            forest.link(u, v);
            soma += it->c;
        }
    }
    
    printf("%d", soma);
    
    return 0;
}
