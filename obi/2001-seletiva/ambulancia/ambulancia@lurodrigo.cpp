
/*
    Olimpíada Brasileira de Informática
    Seletiva para a IOI, 2001
    Problema: Ambulância
    
    Data de submissão: 29/05/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: backtracking
    Complexidade: ?

*/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int edge[100][100], nedges[100];
bool visited[100];

int path[100];

void print_path(int n) {
    if ( n < 2 ) return;
    
    for (int i = 0; i < n; i++)
        printf("%d ", path[i] + 1);
    printf("\n");
}

void backtrack(int u, int p) {
    visited[u] = true;
    path[p++] = u;
    
    print_path(p);
    for (int i = 0; i < nedges[u]; i++)
        if ( !visited[edge[u][i]] )
            backtrack(edge[u][i], p);
       
    visited[u] = false;
}

int main() {
    
    int i, j, u, v, n, teste = 1;
    
    while (true) {
        cin >> n;
        
        if ( n == 0 ) break;
        
        fill(visited, visited + n, false);
        fill(nedges, nedges + n, 0);
        
        while (true) {
            cin >> u >> v;
            if ( u == 0 ) break;
            u--; v--;
            
            edge[u][nedges[u]++] = v;
        }
        
        for (i = 0; i < n; i++)
            sort(edge[i], edge[i] + nedges[i]);
        
        printf("Teste %d\n", teste++);
        backtrack(0, 0);
        printf("\n");
    }
    
    return 0;
}
