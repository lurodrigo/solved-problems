
/*
    Olimpíada Brasileira de Informática
    2007, Nível 2, Fase 1
    Problema: Móbile
    
    Data de submissão: 12/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: mapas
    Complexidade: O(n)
*/

#include <iostream>
#include <list>
using namespace std;

struct Peca {
    list<int> filhos;
    int pai, peso;
    
    Peca() {
        peso = 1;
    }
} pecas[10001];

bool balanceado(int r) {
    int prev; 
   
    for (list<int>::iterator it = pecas[r].filhos.begin(); 
    it != pecas[r].filhos.end(); it++) {
        if ( !balanceado(*it) )
            return false;
        if ( it == pecas[r].filhos.begin() ) 
            prev = pecas[*it].peso; 
        if ( pecas[*it].peso != prev )
            return false;
        pecas[r].peso += pecas[*it].peso;
    } 
    
    return true;
}

int main() {
    int n, i, u, v;
    
    cin >> n;
    
    for (i = 0; i < n; i++) {
        cin >> u >> v;
        pecas[u].pai = v;
        pecas[v].filhos.push_back(u);
    }
    
    cout << ((balanceado(0)) ? "bem" : "mal");

    return 0;
}
