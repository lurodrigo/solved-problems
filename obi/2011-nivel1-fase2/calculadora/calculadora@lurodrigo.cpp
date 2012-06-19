
/*
    Olimpíada Brasileira de Informática
    Nível 1, Fase 2, 2011
    Problema: Calculadora
    Data de submissão: 13/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: aritmética, ad-hoc
    Complexidade: O(n)
    
    Na minha opinião, a questão mais interessante da prova.
*/

#include <iostream>
using namespace std;

int t[10][4] = {
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {1, 0, 0, 0},
    {0, 1, 0, 0},
    {2, 0, 0, 0},
    {0, 0, 1, 0},
    {1, 1, 0, 0},
    {0, 0, 0, 1},
    {3, 0, 0, 0},
    {0, 2, 0, 0}
};

int p[4] = {2, 3, 5, 7};

int main() {
    int i, j, n, d, res = 1;
    int tr[4] = {0, 0, 0, 0};
    char op;
    cin >> n;
    
    for (i = 0; i < n; i++) {
        cin >> d >> op;
        
        for (j = 0; j < 4; j++) 
            if ( op == '*' )
                tr[j] += t[d][j];
            else
                tr[j] -= t[d][j];
    }
    
    for (i = 0; i < 4; i++) {
        for (j = 0; j < tr[i]; j++)
            res *= p[i];
    }
    
    cout << res;
    
    return 0;
}
