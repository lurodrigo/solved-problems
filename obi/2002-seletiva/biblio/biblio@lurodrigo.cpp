
/*
    Olimpíada Brasileira de Informática
    Seletiva para a IOI, 2002
    Problema: Biblioteca Ótima
    
    Data de submissão: 22/05/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: programacao-dinamica
    Complexidade: O(n³)
*/

#include <iostream>
#include <cstdio>
using namespace std;

int s[62], c[62], m[62][62];

int sum(int i, int j) {
    if ( i > j ) return 0;
    return s[j] - s[i-1];
}

int mincost(int n) {
    int i, j, k, l;
    
    for (i = 1; i <= n+1; i++)
        for (j = 0; j <= n; j++)
            m[i][j] = 0;
            
    for (i = 1; i <= j; i++)
        s[i] = s[i-1] + c[i];
    
    for (l = 2; l <= n; l++)
        for (i = 1, j = i+l-1; j <= n; i++, j++)
            for (m[i][j] = 1 << 28, k = i; k <= j; k++)
                m[i][j] = min(m[i][j], m[i][k-1] + sum(i, k-1) +
                    m[k+1][j] + sum(k+1, j));
         
    return m[1][n];
}

int main() {

    int i, n, teste=1;
    
    while (true) {
        cin >> n;
        
        if ( n == 0 )
            break;
            
        for (i = 1; i <= n; i++)
            cin >> c[i];
           
        printf("Teste %d\n%d\n\n", teste++, mincost(n));
    }

    return 0;
}
