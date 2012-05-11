
/*
    Olimpíada Brasileira de Informática
    2003, Seletiva IOI
    Problema: Manutenção
    
    Data de submissão: 10/05/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: grafos, vertices-de-articulacao
    Complexidade: O(n+m)
*/

#include <iostream>
#include <cstdio>
#include <list>
#include <stack>
using namespace std;

struct Node {
    bool visited;
    int children, parent;
    list<int> adj;
    list<int>::iterator it;
} g[400];

void prepare(int n) {
    for (int i = 0; i < n; i++) {
        g[i].visited = false;
        g[i].children = 0;
        g[i].parent = i;
        g[i].adj.clear();
    }
}

void visit(int i) {
    stack<int> s;
    int u, v;
    
    s.push(i);
    while ( !s.empty() ) {
        u = s.top();
        g[u].visited = true;
        
        if ( g[u].it == g[u].adj.end() )
            s.pop();
        else {
            v = *g[u].it;
            g[u].it++;
            
            if ( !g[v].visited ) {
                g[u].children++;
                g[v].parent = u;
                s.push(v);
            }
        }
    }
}

list<int> artic(int n) {
    list<int> order;
    list<int>::iterator it;
    
    for (int i = 0; i < n; i++)
        if ( !g[i].visited )
            visit(i);
}

int main() {
    int n, m, u, v, i, teste=1;

    while (true) {
        cin >> n >> m;
        
        if ( n == 0 ) break;
        
        prepare(n);
        
        for (i = 0; i < m; i++) {
            cin >> u >> v;
            u--; v--;
            g[u].adj.push_back(v);
            g[v].adj.push_back(u);
        }
        
        for (i = 0; i < n; i++) {
            g[i].it = g[i].adj.begin();
        }
        
    }
    
    return 0;
};
