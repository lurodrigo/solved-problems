
/*
    Olimpíada Brasileira de Informática
    Nível 1, Fase 2, 2011
    Problema: Selos
    Data de submissão: 13/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: aritmética
    Complexidade: O(sqrt(n))
*/

#include <iostream>
using namespace std;

int main() {
    int i, n;
    cin >> n;
    
    for (i = 2; i*i <= n; i++)
        if ( n % i == 0 ) {
            cout << "S";
            return 0;
        }
    
    cout << "N";
    return 0;
}
