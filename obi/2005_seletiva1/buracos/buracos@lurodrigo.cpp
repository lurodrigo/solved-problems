
/*
    Olimpíada Brasileira de Informática
    2005, Seletiva IOI, Prova I
    Problema: Buracos de minhoca
    
    Data de submissão: 10/05/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: grafos, componentes-fortemente-conectados, conectividade
    Complexidade: O(n+m)
*/

#include <iostream>
#include <cstdio>
#include <list>
#include <stack>
using namespace std;

struct Node {
    bool visited;
    list<int> adj;
    list<int>::iterator it;
} g[3000], gt[3000];

void prepare(int n) {
    for (int i = 0; i < n; i++) {
        g[i].visited = false;
        g[i].adj.clear();
        
        gt[i].visited = false;
        gt[i].adj.clear();
    }
}

void visit(Node g[], int i, list<int> &res) {
    stack<int> s;
    int u, v;
    
    s.push(i);
    while ( !s.empty() ) {
        u = s.top();
        g[u].visited = true;
        
        if ( g[u].it == g[u].adj.end() ) {
            s.pop();
            res.push_front(u);
        } else {
            v = *g[u].it;
            g[u].it++;
            
            if ( !g[v].visited )
                s.push(v);
        }
    }
}

int count_sccs(int n) {
    list<int> order, dummy;
    list<int>::iterator it;
    int i, count;
    
    for (int i = 0; i < n; i++)
        if ( !g[i].visited )
            visit(g, i, order);
            
    count = 0;
    for (it = order.begin(); it != order.end(); it++)
        if ( !gt[*it].visited ) {
            visit(gt, *it, dummy);
            count++;
        }
         
    return count;
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
            gt[v].adj.push_back(u);
        }
        
        for (i = 0; i < n; i++) {
            g[i].it = g[i].adj.begin();
            gt[i].it = gt[i].adj.begin();
        }
        
        printf("Teste %d\n%c\n\n", teste++, ((count_sccs(n) == 1) ? 'S' : 'N'));
    }

    return 0;
}
