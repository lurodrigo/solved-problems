
/*
    Olimpíada Brasileira de Informática
    Seletiva para a IOI, Teste II, 2005
    Problema: O Problema do Caixeiro Viajante
    
    Data de submissão: 25/05/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: grafos, busca-em-profundidade
    Complexidade: O(n log n)
*/

#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

struct Node {
    int cost, nadj;
    bool visited;
    int adj[300];
} nodes[300];

set<int> to_visit;

int cost_node(int u) {
    return (to_visit.find(u) != to_visit.end()) ? 2 : 0;
}

int dfs(int u) {
    int cost_children = 0;
    
    nodes[u].visited = true;
    for (int v = 0; v < nodes[u].nadj; v++)
        if ( !nodes[nodes[u].adj[v]].visited )
            cost_children += dfs(nodes[u].adj[v]);
    
    if ( cost_children == 0 )
        return cost_node(u);
    else
        return 2 + cost_children;
}

int main() {

    int n, m, i, x, u, v, teste=1;
    
    while (true) {
        cin >> n >> m;
        
        if ( n == 0 ) 
            break;
        
        to_visit.clear();
        for (i = 0; i < n; i++) {
            nodes[i].nadj = 0;
            nodes[i].visited = false;
        }
        
        for (i = 0; i < n-1; i++) {
            cin >> u >> v;
            u--; v--;
            nodes[u].adj[nodes[u].nadj++] = v;
            nodes[v].adj[nodes[v].nadj++] = u;
        }
        
        for (i = 0; i < m; i++) {
            cin >> x;
            to_visit.insert(--x);
        }
        
        printf("Teste %d\n%d\n\n", teste++, dfs(0) - 2);
    }
    
    return 0;
}