
/*
    Olimpíada Brasileira de Informática
    Nível 2, Fase 2, 2012
    Problema: Bomba
    
    Data de submissão: 12/05/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: grafos, busca-em-largura, grafos-multicamada
    Complexidade: O(n+m)
*/

#include <iostream>
#include <list>
#include <queue>
using namespace std;

struct Node {
    bool visited;
    int dist;
    list<int> adj;
} g[1500];

const int UNDEF = 1 << 28;

void bfs(int n, int o) {
    queue<int> q;
    int i, u;
    list<int>::iterator it;

    for (i = 0; i < n; i++) {
        g[i].visited = false;
        g[i].dist = UNDEF;
    }

    q.push(o);
    g[o].visited = true;
    g[o].dist = 0;
    while ( !q.empty() ) {
        u = q.front();
        q.pop();

        for (it = g[u].adj.begin(); it != g[u].adj.end(); it++)
            if ( !g[*it].visited ) {
                g[*it].visited = true;
                g[*it].dist = g[u].dist + 1;
                q.push(*it);
            }
    }
}

int main() {

    int n, e, s, m, i, u, v, t;

    cin >> n >> e >> s >> m;

    for (i = 0; i < m; i++) {
        cin >> u >> v >> t;

        if ( t == 1 )
            g[3*u].adj.push_back(3*v+1);
        else {
            g[3*u+1].adj.push_back(3*v+2);
            g[3*u+2].adj.push_back(3*v);
        }
    }

    bfs(3*n, 3*e);
    m = min(min(g[3*s].dist, g[3*s+1].dist), g[3*s+2].dist);

    if ( !g[3*s].visited && !g[3*s+1].visited && !g[3*s+2].visited )
        cout << "*";
    else
        cout << m;

    cout << endl;
    
    return 0;
}
