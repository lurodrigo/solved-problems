
/*
    Olimpíada Brasileira de Informática
    Seletiva IOI 2006
    Problema: Pérolas
    
    Data de submissão: 13/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: grafos, busca-em-largura
    Complexidade: O(n*(n+m))
*/

#include <iostream>
#include <cstdio>
#include <list>
#include <queue>
using namespace std;

struct Pearl {
    bool visited;
    list<int> adj;
} p_less[100], p_greater[100];

void set_unvisited(Pearl pearls[], int n) {
    for (int i = 0; i < n; i++)
        pearls[i].visited = false;
}

int bfs(Pearl pearls[], int n, int i) {
    queue<int> q;
    list<int>::iterator it;
    int count = -1;
    
    set_unvisited(pearls, n);
    
    q.push(i);
    while ( !q.empty() ) {
        i = q.front();
        q.pop();
        count++;
        
        for (it = pearls[i].adj.begin(); it != pearls[i].adj.end(); it++) 
            if ( !pearls[*it].visited ) {
                pearls[*it].visited = true;
                q.push(*it);
            }
    }
    
    return count;
}

int main() {
    int n, m, i, j, u, v, count = 0;
    
    cin >> n >> m;
    
    for (i = 0; i < m; i++) {
        cin >> u >> v;
        u--; v--;
        p_greater[u].adj.push_back(v);
        p_less[v].adj.push_back(u);
    }
        
    for (i = 0; i < n; i++)
        if ( bfs(p_less, n, i) > n/2 || bfs(p_greater, n, i) > n/2 )
            count++;
    
    printf("%d\n", count);
        
    return 0;
}
