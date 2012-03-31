
/*
    Olimpíada Brasileira de Informática
    Nível 2, Fase 2, 2011
    Problema: Reduzindo detalhes de um mapa
    
    Data de submissão: 30/03/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: grafos, arvore-custo-minimo, algoritmos-gulosos, algoritmo-prim
    Complexidade: O(N²)
*/

#include <iostream>
#include <cstdio>
using namespace std;

const int UNDEFINED = 1 << 29;

struct Node {
    int key;
    bool in_queue;
    int adj[500];
    
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
    for (i = min; i < len; i++) 
        if ( nodes[i].in_queue && nodes[i].key < nodes[min].key )
            min = i;
            
    nodes[min].in_queue = false;
    return min;
}

int main() {

    Node nodes[500];
    int ncidades, nrodovias, i, j, u, v, c;
    
    scanf("%d%d", &ncidades, &nrodovias);
    
    for (i = 0; i < ncidades; i++)
        nodes[i].init(ncidades);
    
    for (i = 0; i < nrodovias; i++) {
        scanf("%d%d%d", &u, &v, &c);
        u--; v--;
        nodes[u].adj[v] = nodes[v].adj[u] = c;
    }

    nodes[0].key = 0;
    for (i = 0; i < ncidades; i++) {
        int min = extract_min(nodes, ncidades);
        
        for (j = 0; j < ncidades; j++) {
            if ( nodes[j].in_queue && nodes[min].adj[j] < nodes[j].key )
                nodes[j].key = nodes[min].adj[j];
        }
    }
    
    int soma = 0;
    
    for (i = 0; i < ncidades; i++) 
        soma += nodes[i].key;

    printf("%d", soma);

    return 0;
}
