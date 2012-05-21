
/*
    Olimpíada Brasileira de Informática
    Seletiva para a IOI, Teste II, 2007
    Problema: Estrada Romana
    
    Data de submissão: 17/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: programacao-dinamica, algoritmos-gulosos, arvore-custo-minimo
    Complexidade: O(n + mlogn)
    
    Solução 1: Usa o algoritmo de Kruskal como base
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct DisjointSets {
    int parent[250], rank[250];
    int size, nsets;
    
    DisjointSets(int n = 0) {
        size = nsets = n;
        
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    
    int find(int a) {
        if ( parent[a] != a )
            parent[a] = find(parent[a]);
        return parent[a]; 
    }
    
    void link(int a, int b) {
        if ( rank[a] > rank[b] )
            parent[b] = a;
        else {
            parent[a] = b;
            if ( rank[a] == rank[b] )
                rank[b]++;
        }
        nsets--;
    }
};

struct Edge {
    int u, v, weight;

    Edge(int a, int b, int c) : u(a), v(b), weight(c) {}
};

bool byWeight(Edge a, Edge b) {
    return a.weight < b.weight;
}

int countWays[101];

int main() {

    int n, p, e, i, j, u, v, l, time = 0;
    
    cin >> n >> p >> e;
    
    DisjointSets sets(n);
    
    countWays[0] = 1;
    for (j = 1; j <= p; j++) {
        cin >> l;
        for (i = l; i <= 100; i++)
            countWays[i] += countWays[i-l];
    }
    
    vector<Edge> edges;
    edges.reserve(e);
    
    for (i = 0; i < e; i++) {
        cin >> u >> v >> l;
        
        if ( countWays[l] > 0 )
            edges.push_back(Edge(--u, --v, countWays[l]));
    }
    
    sort(edges.begin(), edges.end(), byWeight);

    for (i = 0; i < edges.size(); i++)
        if ( sets.find(edges[i].u) != sets.find(edges[i].v) ) {
            sets.link(edges[i].u, edges[i].v);
            time += edges[i].weight;
        }
          
    if ( sets.nsets == 1 )
        cout << time;
    else
        cout << -1;

    return 0;
}