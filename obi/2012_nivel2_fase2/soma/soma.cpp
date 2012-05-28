
/*
    Olimpíada Brasileira de Informática
    Nível 2, Fase 2, 2012
    Problema: Somas
    
    Data de submissão: 12/05/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: busca-binaria
    Complexidade: O(n log n)
    
    Ps: existe um algoritmo bem simples com complexidade O(n), o qual
    não utilizei simplesmente por não ser necessário dado o tamanho da entrada
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int i, n, k, a[100000];

    cin >> n;

    for (i = 0; i < n; i++)
        cin >> a[i];

    cin >> k;

    for (i = 0; i < n && a[i] <= k/2; i++)
        if ( binary_search(a+i+1, a+n, k-a[i]) ) {
            cout << a[i] << " " << k-a[i];
            break;
        }

    return 0;
}
