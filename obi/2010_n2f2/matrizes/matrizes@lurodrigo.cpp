
/*
    Olimpíada Brasileira de Informática
    Nível 2, Fase 2, 2010
    Problema: Multiplicação de matrizes
    
    Data de submissão: 02/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: aritmética
    Complexidade: O(n)
*/

#include <iostream>
using namespace std;

int main() {
    
    int n, i, j, k, p, q, x, r, s, y, c = 0;
    
    cin >> n;
    cin >> p >> q >> r >> s >> x >> y;
    cin >> i >> j;
    
    for (k = 1; k <= n; k++)
        c += ((p*i + q*k) % x) * ((r*k + s*j)% y);

    cout << c;
    
    return 0;
}
