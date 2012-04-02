
/*
    Olimpíada Brasileira de Informática
    Nível 2, Fase 1, 2011
    Problema: Desenho Cartográfico
    
    Data de submissão: 30/03/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: grafos, busca-em-largura, diametro-do-grafo, arvore
    Complexidade: O(n)
*/

#include <iostream>
#include <list>
#include <queue>
using namespace std;

const int UNDEFINED = 1 << 28;

struct Node {
    int dist;
    list<int> adj;
};

int bfs(Node cidades[], int n, int origin) {
    queue<int> fila;
    
    for (int i = 0; i < n; i++)
        cidades[i].dist = UNDEFINED;
    cidades[origin].dist = 0;
    fila.push(origin);
    
    while ( !fila.empty() ) {
        int u = fila.front();
        fila.pop();
        
        for (list<int>::iterator it = cidades[u].adj.begin();
                it != cidades[u].adj.end(); it++) 
            if ( cidades[*it].dist == UNDEFINED ) {
                cidades[*it].dist = cidades[u].dist + 1;
                fila.push(*it);
            }
    }
    
    int imax = origin;
    for (int i = 0; i < n; i++)
        if ( cidades[i].dist > cidades[imax].dist )
            imax = i;
            
    return imax; 
}

int main() { 

    int n, u, v;
    Node cidades[100000];
    
    cin >> n;
    
    for (int i = 0; i < n-1; i++) {
        cin >> u >> v;
        u--; v--;
        cidades[u].adj.push_back(v);
        cidades[v].adj.push_back(u);
    }
    
    u = bfs(cidades, n, 0);
    v = bfs(cidades, n, u);
    
    cout << cidades[v].dist;

    return 0;
}
