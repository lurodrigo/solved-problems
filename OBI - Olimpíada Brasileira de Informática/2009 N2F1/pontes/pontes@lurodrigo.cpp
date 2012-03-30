
/*
    Olimpíada Brasileira de Informática
    Nível 2, Fase 1, 2009
    Problema: Caminho das pontes
    
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: grafos, algoritmos-gulosos, menor-caminho, algoritmo-dijkstra
    Complexidade: O(N²)
*/


#include <cstdio>
using namespace std;

const int UNDEFINED = 1 << 28;

struct Node {
    int dist;
    int adj[1002];
    bool in_queue;
    
    Node() {
        dist = UNDEFINED;
        in_queue = true;
    }
    
    void init(int n) {
        for (int i = 0; i < n; i++)
            adj[i] = UNDEFINED;
    }
};

int extract_min(Node nodes[], int len) {
    int i, min;
    
    for (min = 0; !nodes[min].in_queue; min++);
    for (i = min + 1; i < len; i++) 
        if ( nodes[i].in_queue && nodes[i].dist < nodes[min].dist )
            min = i;
            
    nodes[min].in_queue = false;
    return min;
}

void relax(Node nodes[], int u, int v) {
    if ( nodes[u].dist + nodes[u].adj[v] < nodes[v].dist )
        nodes[v].dist = nodes[u].dist + nodes[u].adj[v];
}

int main() {

    Node nodes[1002];
    int i, j, min, n, m, u, v, c;
    
    scanf("%d%d", &n, &m);
    
    n += 2;
    
    for (i = 0; i < n; i++) {
        nodes[i].init(n);
    }
    nodes[0].dist = 0;
    for (i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &c);
        
        nodes[u].adj[v] = nodes[v].adj[u] = c;
    }
    
    for (i = 0; i < n; i++) {
        min = extract_min(nodes, n);
        
        for (j = 0; j < n; j++) 
            relax(nodes, min, j);
    }
    
    printf("%d", nodes[n-1].dist);
    
    return 0;
}