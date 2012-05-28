
/*
    Olimpíada Brasileira de Informática
    Nível 2, Fase 2, 2007
    Problema: Pizza
    
    Data de submissão: 13/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: programacao-dinamica, maior-soma-sequencia
    Complexidade: O(n)
*/

#include <iostream>
using namespace std;

int main() {

    int i, m, n;
    int d[200000];
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> d[i];

    for (i = n; i < 2*n-1; i++)
        d[i] = d[i-n];
    
    m = max(0, d[0]);
    for (i = 1; i < 2*n-1; i++) {
        d[i] = max(d[i], d[i] + d[i-1]);
        m = max(m, d[i]);
    }
    
    cout << m;
        
    return 0;
}