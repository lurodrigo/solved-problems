
/*
    Olimpíada Brasileira de Informática
    2003, Seletiva IOI
    Problema: Manutenção
    
    Data de submissão: 29/05/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: grafos, vertices-de-articulacao
    Complexidade: O(n*(n+m))
    
    Solução 1: brute-force
    Testa, para todos os vértices v, se o grafo se mantém conexo após a 
    remoçao de v 
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int edge[400][400], nedges[400];
bool visited[400];

void dfs(int u) {
    visited[u] = true;
    
    for (int i = 0; i < nedges[u]; i++)
        if ( !visited[edge[u][i]] )
            dfs(edge[u][i]);
}

bool conexo(int n, int p) {
    fill(visited, visited + n, false);
    visited[p] = true;
    dfs((p + 1) % n);
    
    return count(visited, visited + n, false) == 0;
}

int main() {
    int n, m, i, j, u, v, conta, teste = 1;
    
    while (true) {
        cin >> n >> m;
        
        if ( n == 0 ) break;
        
        fill(nedges, nedges + n, 0);
        for (i = 0; i < m; i++) {
            cin >> u >> v;
            u--; v--;
            edge[u][nedges[u]++] = v;
            edge[v][nedges[v]++] = u;
        }
        
        printf("Teste %d\n", teste++);
        for (conta = i = 0; i < n; i++)
            if ( !conexo(n, i) ) {
                printf("%d ", i + 1);
                conta++;
            }
            
        if ( conta == 0 )
            printf("nenhum");
                
        printf("\n\n");
    }

    return 0;
}
