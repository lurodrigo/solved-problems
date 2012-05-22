
/*
    Olimpíada Brasileira de Informática
    OBI 2007, Nível 2, Fase 2
    Problema: Labirinto
    
    Data de submissão: 17/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: grafos, busca-em-largura
    Complexidade: O(n*m)
*/

#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

struct Node {
    int d, h;
    bool visited;
    int adj[5];
} nodes[25001];

int n, m;

const int dummy = 25000;
int idx(int row, int column, int time) {
    if ( row >= 0 && row < n && column >= 0 && column < m && time >= 0 && time < 10 )
        return 10*m*row + 10*column + time;
    else
        return dummy; // dummy node
}

void bfs() {
    queue<int> q;
    
    nodes[0].d = 0;
    nodes[0].visited = true;
    q.push(0);
    while ( !q.empty() ) {
        int u = q.front();
        q.pop();
        
        for (int i = 0; i < 5; i++)
            if ( !nodes[nodes[u].adj[i]].visited ) {
                nodes[nodes[u].adj[i]].d = nodes[u].d + 1;
                nodes[nodes[u].adj[i]].visited = true;
                q.push(nodes[u].adj[i]);
            }
    }
}

const int dir[5][2] = { {0, -1}, {0, 0}, {0, 1}, {-1, 0}, {1, 0} };

int main() {
    int i, j, k, h, l, r;
    
    cin >> n >> m;
    
    nodes[idx(-1, -1, -1)].d = 1 << 28;
    
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++) {
            cin >> h;
            for (k = 0; k < 10; k++) 
                nodes[idx(i, j, k)].h = (h + k) % 10;
        }
    
    for (i = 0; i < n; i++) 
      for (j = 0; j < m; j++)
        for (k = 0; k < 10; k++)
          for (l = 0; l < 5; l++)
            if ( nodes[idx(i + dir[l][0], j + dir[l][1], k % 10)].h <= nodes[idx(i, j, k)].h + 1 )
              nodes[idx(i, j, k)].adj[l] = idx(i + dir[l][0], j + dir[l][1], (k+1) % 10);
            else
              nodes[idx(i, j, k)].adj[l] = dummy;
               
    bfs();           
               
    r = nodes[idx(n-1, m-1, 0)].d;
    for (k = 1; k < 10; k++)
        r = min(r, nodes[idx(n-1, m-1, k)].d);
    
    cout << r;
    
    return 0;
}
