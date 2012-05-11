
/*
    Olimpíada Brasileira de Informática
    Seletiva IOI 2006
    Problema: Pérolas
    
    Data de submissão: 13/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: grafos, dag, ordenacao-topologica
    Complexidade: O(n³)
*/

#include <iostream>
#include <cstdio>
#include <list>
#include <stack>
using namespace std;

Node {
    bool visited;
    list<int> in, out, is_lesser, is_greater;
    list<int>::iterator it;
} p[100];

void inplace_union(list<int> &a, list<int> &b) {
    list<int> aux;
    set_union(a.begin(), a.end(), b.begin(), b.end(), aux);
    a = aux;
}

void visit(int i, list<int> &sorted) {
    stack<int> s;
    int u, v;
    
    s.push(i);
    while ( !s.empty() ) {
        u = s.top();
        p[u].visited = true;
        
        if ( p[u].it == p[u].out.end() ) {
            s.pop();
            sorted.push_front(u);
        } else {
            v = *(p[u].it);
            p[u].it++;
            
            if ( !p[v].visited )
                s.push(v);
        }
    }
}

void topological_sort(int n, list<int> &sorted) {
    int i;
    
    for (i = 1; i <= n; i++)
        p[i].it = p[i].out.begin();
        
    for (i = 1; i <= n; i++)
        if ( !p[i].visited )
            visit(i, sorted);
}

int main() {

    int n, m, u, v, i;
    list<int> sorted;
    list<int>::iterator it, jt;
    
    cin >> n >> m;
    
    for (i = 0; i < m; i++) {
        cin >> u >> v;
        p[u].out.push_back(v);
        p[v].in.push_back(u);
    }

    topological_sort(n, sorted);
    
    for (it = sorted.begin(); it != sorted.end(); it++) {
        p[*it].is_lower = p[*it].in;
        p[*it].is_lower.sort();
        
        for (jt = p[*it].in.begin(); jt != p[*it].in.end(); jt++)
            inplace_union(p[*it].is_lower(), p[*it].is_lower());
    }
    
    for (it = sorted.rbegin(); it != sorted.rend(); it++) {
        p[*it].is_greater = p[*it].out;
        p[*it].is_greater.sort();
        
        for (jt = p[*it].out.begin(); jt != p[*it].out.end(); jt++)
            inplace_union(p[*it].is_greater, p[*jt].is_greater);
    }
    
    for (i = 1; i <= n; i++)
        if ( p[i].is_lower.size() > n/2 || p[i].is_greater.size() > n/2 )
            cout << i << " ";
        
    return 0;
}