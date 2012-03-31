
/*
    Olimpíada Brasileira de Informática
    Nível 2, Fase 2, 2008
    Problema: Frete da Família Silva
    
    Data de submissão: 29/03/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: grafos, algoritmos-gulosos, arvore-custo-minimo, algoritmo-prim
    Complexidade: O(N²)
*/

#include <cstdio>
using namespace std;

const int UNDEFINED = 1 << 28;

struct Node {
    int key;
    int adj[1000];
    bool in_queue;
    
    Node() {
        key = UNDEFINED;
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
        if ( nodes[i].in_queue && nodes[i].key < nodes[min].key )
            min = i;
            
    nodes[min].in_queue = false;
    return min;
}

int main() {

    Node nodes[1000];
    int i, j, min, u, v, c, n, m, sum;
    
    scanf("%d%d", &n, &m);
    
    for (i = 0; i < n; i++)
        nodes[i].init(n);
    nodes[0].key = 0;
        
    for (i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &c);
        nodes[u].adj[v] = nodes[v].adj[u] = c;
    }

    for (i = 0; i < n; i++) {
        min = extract_min(nodes, n);
        
        for (j = 0; j < n; j++) {
            if ( nodes[j].in_queue && nodes[min].adj[j] < nodes[j].key )
                nodes[j].key = nodes[min].adj[j];
    }
    
    sum = 0;
    for (i = 0; i < n; i++)
        sum += nodes[i].key;
        
    printf("%d", sum);

    return 0;
}
