
/*
    Olimpíada Brasileira de Informática
    Nível 2, 2005
    Problema: Transmissão de energia
    
    Data de submissão: 12/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: grafos, conectivade, busca-em-largura
    Complexidade: O(N+M)
*/

#include <iostream>
#include <list>
#include <queue>
using namespace std;

struct Node {
    bool reachable;
    list<int> adj;
};

bool connected(Node nodes[], int n) {
    queue<int> q;
    
    for (int i = 0; i < n; i++)
        nodes[i].reachable = false;
        
    nodes[0].reachable = true;
    int count = 1;
    q.push(0);
    
    while ( !q.empty() ) {
        int u = q.front();
        q.pop();
        
        for (list<int>::iterator it = nodes[u].adj.begin(); it != nodes[u].adj.end(); it++)
            if ( !nodes[*it].reachable ) {
                nodes[*it].reachable = true;
                q.push(*it);
                count++;
                
                if ( count == n ) 
                    return true;
            }
    }
    
    return false;
}

int main() {

    Node nodes[100];
    int n, m, u, v, i, teste = 1;
    
    while (true) {
        cin >> n >> m;
        
        if (n == 0) 
            break;
            
        for (i = 0; i < n; i++)
            nodes[i].adj.clear();
        
        for (i = 0; i < m; i++) {
            cin >> u >> v;
            u--; v--;
            
            nodes[u].adj.push_back(v);
            nodes[v].adj.push_back(u);
        }
    
        cout << "Teste " << teste++ << endl;
        cout << (connected(nodes, n) ? "normal" : "falha") << endl << endl; 
    }
    

    return 0;
}