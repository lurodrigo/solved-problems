
/*
    Olimpíada Brasileira de Informática
    Nível 2, Fase 2, 2011
    Problema: Escalonamento Ótimo
    
    Data de submissão: 13/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: grafos, ordenacao-topologica, ordenacao-lexicografica, conjuntos
    Complexidade: O(n log n + m)
    
    Versão 1: Utiliza conjuntos para manter os vértices com graus zero
*/

#include <iostream>
#include <set>
#include <list>
using namespace std;

struct Node {
    int degree;
    list<int> edges;
};

int main() {

    Node nodes[50000];
    int sorted[50000];
    set<int> zeroes;
    int i, j, u, v, n, m, count = 0;
    
    cin >> n >> m;
    
    for (i = 0; i < n; i++) 
        nodes[i].degree = 0;
    
    for (i = 0; i < m; i++) {
        cin >> u >> v;
        nodes[u].edges.push_back(v);
        nodes[v].degree++;
    }
    
    for (i = 0; i < n; i++)
        if ( nodes[i].degree == 0 )
            zeroes.insert(i);
            
    while ( !zeroes.empty() ) {
        u = *zeroes.begin();
        zeroes.erase(zeroes.begin());
        sorted[count++] = u;
        
        for (list<int>::iterator it = nodes[u].edges.begin(); it != nodes[u].edges.end(); it++) {
            nodes[*it].degree--;
            
            if ( nodes[*it].degree == 0 )
                zeroes.insert(*it);
        }
    }
    
    if ( n ! count ) 
        cout << '*';
    else 
        for (i = 0; i < n; i++)
            cout << sorted[i] << endl;

    return 0;
}