
/*
    Olimpíada Brasileira de Informática
    2003, Seletiva IOI
    Problema: Manutenção
    
    Data de submissão: 29/05/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: grafos, vertices-de-articulacao
    Complexidade: O(n+m)
    
    Solução 2: Procura por pontos de articulação
    
    Estratégia similar ao do problema 22-2 do Cormen (3rd Edition).
    
    Computa, para cada vértice, o tempo de descoberta .d e o .low
    definido como:
    
    v.low = min { v.d
                { u.d | f, u in V-{v} e (f, u) in E 
    
    Um vértice v é de articulação se e somente se 
    - for a raiz da árvore da dfs e tiver mais de dois filhos nela
    - não for a raiz e tiver algum filho f com f.low > v.d
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int edge[400][400], nedges[400], discovered[400], tempo, children;
bool visited[400], eArt[400];

int dfs(int u, int parent, bool root) {
    int i, low, low_child;
    visited[u] = true;
    discovered[u] = ++tempo;
   
    if ( root ) 
        children = 0;
   
    for (i = 0, low = tempo; i < nedges[u]; i++)
        if ( visited[edge[u][i]] && edge[u][i] != parent ) 
            low = min(low, discovered[edge[u][i]]);
        else if ( !visited[edge[u][i]] ) {
            low_child = dfs(edge[u][i], u, false);
            if ( low_child > discovered[u] ) 
                eArt[u] = true;
            low = min(low, low_child);
            
            if ( root )
                children++;
        } 
        
    if ( root )
        eArt[u] = (children >= 2);
        
    return low;
}

int main() {
    int n, m, i, j, u, v, teste = 1;
    
    while (true) {
        cin >> n >> m;
        
        if ( n == 0 ) break;
        
        fill(nedges, nedges + n, 0);
        fill(eArt, eArt + n, false);
        fill(visited, visited + n, false);
        for (i = 0; i < m; i++) {
            cin >> u >> v;
            u--; v--;
            edge[u][nedges[u]++] = v;
            edge[v][nedges[v]++] = u;
        }
        
        tempo = 0;
        dfs(0, 0, true);
        
        printf("Teste %d\n", teste++);
        for (i = 0; i < n; i++)
            if ( eArt[i] )
                printf("%d ", i + 1);
            
        if ( count(eArt, eArt + n, true) == 0 )
            printf("nenhum");
                
        printf("\n\n");
    }

    return 0;
}
