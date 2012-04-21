
/*
    Olimpíada Brasileira de Informática
    Nível 2, Fase 1, 2006
    Problema: Escada Perfeita
    
    Data de submissão: 21/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: ad-hoc, comparações, aritmética
    Complexidade: O(n)
*/

#include <iostream>
using namespace std;

int main() {

    int i, n, h[10001], k, count = 0, soma = 0;

    cin >> n;
    
    for (i = 1; i <= n; i++) {
        cin >> h[i];
        soma += h[i];
    }
    
    k = soma - n*(n+1)/2;
    
    if ( k < 0 || k % n != 0 ) {
        cout << -1;
    } else {
        k /= n;
        for (i = 1; i <= n; i++)
            if ( h[i] > k + i )
                count += h[i]-k-i;

        cout << count;
    }
    
    return 0;
}
