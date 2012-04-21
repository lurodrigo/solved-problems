
/*
    Olimpíada Brasileira de Informática
    Nível 2, Fase 1, 2006
    Problema: Jogo de Cartas
    
    Data de submissão: 20/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: ad-hoc, comparações
    Complexidade: O(n)
*/

#include <iostream>
using namespace std;

int main() {
    int i, n, prev, act, count = 0;
    
    cin >> n;
    
    for (prev = n + 1, i = 0; i < n; i++) {
        cin >> act;
        
        if ( act < prev ) 
            count++;
        prev = act;
    } 

    cout << count;

    return 0;
}
