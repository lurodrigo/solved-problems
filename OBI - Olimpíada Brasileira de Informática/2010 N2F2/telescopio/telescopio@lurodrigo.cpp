
/*
    Olimpíada Brasileira de Informática
    Nível 2, Fase 2, 2010
    Problema: Telescópio
    
    Data de submissão: 02/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: aritmética
    Complexidade: O(n)
*/

#include <iostream>
using namespace std;

int main() {

    int a, n, f, c = 0;
    
    cin >> a >> n;
    
    while ( n-- ) {
        cin >> f;
        
        if ( a*f >= 40000000 )
            c++;
    }

    cout << c;
    
    return 0;
}
