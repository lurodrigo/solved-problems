/*
    Olimpíada Brasileira de Informática
    Nível 2, Fase 2, 2010
    Problema: Floresta
    
    Data de submissão: 02/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: aritmética, equações
    Complexidade: O(x)
*/

#include <iostream>
using namespace std;

int main() {

    int n, x, y, c = 0;
    
    cin >> n;
    
    for (int i = 2; i*i <= n; i++) {
        if ( (n + i - 1) % (2*i - 1) == 0 && i <= (n + i - 1) / (2*i - 1) )
            c++;
    }

    cout << c;
    
    return 0;
}
