
/*
    Olimpíada Brasileira de Informática
    Seletiva para a IOI, Teste Final, 2008
    Problema: Luzes do palco
    
    Data de submissão: 17/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: grafos
    Complexidade: O(n+m)
*/

#include <iostream>
#include <list>
#include <queue>
using namespace std;

struct Luzes {
    int d;
    bool visited;
    list<int> adj;
} luzes[10000];

int sum_visit(int u) {
    queue<int> q;
    list<int>::iterator it;
    int sum = luzes[u].d;
    
    luzes[u].visited = true;
    q.push(u);
    while ( !q.empty() ) {
        u = q.front();
        q.pop();
        
        for (it = luzes[u].adj.begin(); it != luzes[u].adj.end(); it++)
            if ( !luzes[*it].visited ) {
                sum += luzes[*it].d;
                luzes[*it].visited = true;
                q.push(*it);
            }
    }

    return sum;
}

int main() {
    int n, m, i, j, u, v;
    
    cin >> n >> m;
    
    for (i = 0; i < n; i++)
        cin >> luzes[i].d;
        
    for (i = 0; i < n; i++) {
        cin >> j;
        luzes[i].d = (int) (j != luzes[i].d);
    }
     
    for (i = 0; i < m; i++) {
        cin >> u >> v;
        
        u--; v--;
        luzes[u].adj.push_back(v);
        luzes[v].adj.push_back(u);
    }   
    
    bool result = true;
    for (i = 0; i < n; i++)
        if ( !luzes[i].visited && (u = sum_visit(i)) % 2 == 1 ) {
            result = false;
            break;
        }
        
    cout << (result ? "S" : "N");

    return 0;
} 
