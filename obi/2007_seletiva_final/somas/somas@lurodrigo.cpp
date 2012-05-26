
/*
    Olimpíada Brasileira de Informática
    Seletiva IOI 2007, Teste Final
    Problema: Somas Proibidas
    
    Data de submissão: 13/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: grafos, busca-em-largura, busca-binaria, grafos-bipartidos
    Complexidade: O(n*m)
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <list>
#include <queue>
using namespace std;

struct Node {
    int value;
    bool in_queue, color;
    list<int> adj;
} nodes[100000];

bool byValue(Node a, Node b) {
    return a.value < b.value;
}

bool bfs(int n, int &set1, int o) {
    list<int>::iterator it;
    queue<int> q;
    
    nodes[0].in_queue = true;
    nodes[0].color = false;
    q.push(0);
    
    while ( !q.empty() ) {
        int i = q.front();
        q.pop();
        
        if ( !nodes[i].color )
            set1++;
        
        for (it = nodes[i].adj.begin(); it != nodes[i].adj.end(); it++)
            if ( nodes[*it].in_queue && nodes[*it].color == nodes[i].color )
                return false;
            else if ( !nodes[*it].in_queue ) {
                nodes[*it].in_queue = true;
                nodes[*it].color = !nodes[i].color;
                q.push(*it);
            }
    }
    
    return true;
}

bool isBipartite(int n, int& set1) {
    for (int i = 0; i < n; i++)
        nodes[i].in_queue = false;
   
    set1 = 0;
    for (int i = 0; i < n; i++)
        if ( !nodes[i].in_queue && !bfs(n, set1, i) )
            return false;
    
    return true; 
}

int main() {
    int i, j, k, f, n, m, set1, beg, end;
    
    cin >> n >> m;
    
    for (i = 0; i < n; i++)
        cin >> nodes[i].value;
        
    sort(nodes, nodes + n, byValue);
    
    for (i = 0; i < m; i++) {
        cin >> f;
        
        for (beg = 0, end = n-1; beg < end; )
            if ( nodes[beg].value + nodes[end].value < f ) 
                beg++;
            else if ( nodes[beg].value + nodes[end].value > f )
                end--;
            else {
                nodes[beg].adj.push_back(end);
                nodes[end].adj.push_back(beg);
                beg++, end--;
            } 
    }
    
    if ( isBipartite(n, set1) ) {
        printf("%d ", set1);
        for (i = 0; i < n; i++)
            if ( !nodes[i].color )
                printf("%d ", nodes[i].value);
      
        printf("\n%d ", n-set1);
        for (i = 0; i < n; i++)
            if ( nodes[i].color )
                printf("%d ", nodes[i].value);   
    } else {
        printf("-1\n-1\n");
    }

    return 0;
}
