
/*
    Olimpíada Brasileira de Informática
    2001, Seletiva IOI
    Problema: Batuíra
    
    Data de submissão: 09/05/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: grafos, dijkstra
    Complexidade: O(n**2)
*/

#include <iostream>
#include <cstdio>
using namespace std;

struct Node {
    int dist;
    bool visited;
    
    int adj[101];
} nodes[101];

const int UNDEF = 1 << 28;

int extract_min(int n) {
    int min, i;
    
    for (min = 0; nodes[min].visited; min++);
    for (i = min+1; i < n; i++)
        if ( !nodes[i].visited && nodes[i].dist < nodes[min].dist )
            min = i;
            
    nodes[min].visited = true;
    return min;
}

void relax(int u, int v) {
    nodes[v].dist = min(nodes[v].dist, nodes[u].dist + nodes[u].adj[v]);
}

void clear(int n) {
    for (int i = 0; i < n; i++) {
        nodes[i].visited = false;
        nodes[i].dist = UNDEF;
        for (int j = 0; j < n; j++)
            nodes[i].adj[j] = UNDEF;
    }
    
    nodes[0].dist = 0;
}

int main() {

    int n, u, v, d, i, j, teste=1;

    while (true) {
        cin >> n;
        
        if ( n == 0 ) break;
        printf("Teste %d\n", teste++);
        
        clear(n);
        
        while (true) {
            cin >> u >> v >> d;    
            if ( u == 0 && v == 0 && d == 0 ) break;
            u--; v--;
            nodes[u].adj[v] = nodes[v].adj[u] = d;
        }
        
        for (i = 2; i <= n; i++) {
            u = extract_min(n);
            
            for (v = 0; v < n; v++)
                relax(u, v);
        }
        
        printf("%d\n\n", nodes[n-1].dist);
    }

    return 0;
}
