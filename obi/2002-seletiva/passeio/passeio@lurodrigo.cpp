
/*
    Olimpíada Brasileira de Informática
    2002, Seletiva IOI
    Problema: Passeio de Bicicleta
    
    Data de submissão: 09/05/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: grafos, dag, maior-distancia
    Complexidade: O(n+m)
*/

#include <iostream>
#include <cstdio>
#include <list>
#include <stack>

using namespace std;

struct Node {
    int dist;
    bool visited;
    list<int> adj;
    list<int>::iterator it;
} nodes[150];

int height[150];
const int UNDEF = -(1<<28);

void visit(int i, list<int> &s) {
    int u, v;
    stack<int> next;
    
    next.push(i);
    while ( !next.empty() ) {
        u = next.top();
        nodes[u].visited = true;
        
        if ( nodes[u].it == nodes[u].adj.end() ) {
            next.pop();
            s.push_front(u);
        } else {
            v = *nodes[u].it;
            nodes[u].it++;
            
            if ( !nodes[v].visited )
                next.push(v);
        }
    }
}

void topological_sort(int n, list<int> &s) {
    int i;
    
    for (i = 0; i < n; i++) {
        nodes[i].visited = false;
        nodes[i].it = nodes[i].adj.begin();
    }
        
    for (i = 0; i < n; i++)
        if ( !nodes[i].visited )
            visit(i, s);
}

int main() {
    int n, m, p, i, j, u, v, teste=1, longest;
    list<int> s;

    while (true) {
        cin >> n >> m >> p;
        
        if ( n == 0 ) break;
        
        for (i = 0; i < n; i++)
            cin >> height[i];
            
        for (i = 0; i < m; i++) {
            cin >> u >> v;
            u--; v--;
            
            // só interessa para nós as ligações de descida
            if ( height[u] > height[v] )
                nodes[u].adj.push_back(v);
        }
        
        topological_sort(n, s);
        
        for (i = 0; i < n; i++)
            nodes[i].dist = UNDEF;
            
        longest = nodes[--p].dist = 0; 
        while ( !s.empty() ) {
            u = s.front();
            s.pop_front();

            for (list<int>::iterator it = nodes[u].adj.begin();
            it != nodes[u].adj.end(); it++) {
                nodes[*it].dist = max(nodes[*it].dist, nodes[u].dist+1);  
            }
            
            if ( nodes[u].dist > longest )
                longest = nodes[u].dist;
        }
        
        printf("Teste %d\n%d\n\n", teste++, longest);
    }

    return 0;
}
