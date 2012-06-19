
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
#include <algorithm>
using namespace std;

struct Node {
    bool visited;
    list<int> in, out, is_lesser, is_greater;
    list<int>::iterator it;
} p[100];

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

void print(list<int> &l) {
    for (list<int>::iterator it = l.begin(); it != l.end(); it++)
        cout << *it << " ";
    cout << endl;
}

void inplace_union(list<int>& a, list<int>& b)
{
    /*
    int mid = a.size();
    std::copy(b.begin(), b.end(), std::back_inserter(a));
    std::inplace_merge(a.begin(), a.begin() + mid, a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());
    */
    list<int> aux(100);
    printf("a: ");
    print(a);
    printf("b: ");
    print(b);
    set_union(a.begin(), a.end(), b.begin(), b.end(), aux.begin());
    printf("aux: ");
    print(aux);
    a.clear();
    copy(aux.begin(), aux.end(), a.begin());
}

int main() {

    int n, m, u, v, i;
    list<int> sorted, aux;
    list<int>::iterator it, jt;
    list<int>::reverse_iterator rt;
    
    cin >> n >> m;
    
    for (i = 0; i < m; i++) {
        cin >> u >> v;
        p[u].out.push_back(v);
        p[v].in.push_back(u);
    }

    topological_sort(n, sorted);
    
    for (it = sorted.begin(); it != sorted.end(); it++) {
        p[*it].is_lesser = p[*it].in;
        p[*it].is_lesser.sort();
        for (jt = p[*it].in.begin(); jt != p[*it].in.end(); jt++)
            inplace_union(p[*it].is_lesser, p[*jt].is_lesser);
    }
    
    for (rt = sorted.rbegin(); rt != sorted.rend(); rt++) {
        p[*rt].is_greater = p[*rt].out;
        p[*rt].is_greater.sort();
        
        for (jt = p[*rt].out.begin(); jt != p[*rt].out.end(); jt++)
            inplace_union(p[*rt].is_greater, p[*jt].is_greater);
    }
    
    for (i = 1; i <= n; i++)
        if ( p[i].is_lesser.size() > n/2 || p[i].is_greater.size() > n/2 )
            cout << i << " ";
        
    return 0;
}
