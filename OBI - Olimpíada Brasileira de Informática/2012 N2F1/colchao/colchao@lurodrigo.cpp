
/*
    Olimpíada Brasileira de Informática
    Nível 2, Fase 1, 2012
    Problema: Colchão
    
    Data de submissão: 30/03/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: ad-hoc, geometria, comparações
    Complexidade: O(1)
*/

#include <iostream>
using namespace std;

bool passa(int h, int l, int x, int y) {
    return x <= h && y <= l;
}

int main() {

    int a, b, c, h, l;
    
    cin >> a >> b >> c >> h >> l;
    
    if ( passa(h, l, a, b) || passa(h, l, a, c) ||
            passa(h, l, b, a) || passa(h, l, a, c) ||
            passa(h, l, c, a) || passa(h, l, c, b) ) 
        cout << "S";
    else
        cout << "N";

    return 0;
}
