/*
    Olimpíada Brasileira de Informática
    Nível 2, Fase 1, 2006
    Problema: Colheita de Caju
    
    Data de submissão: 20/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: programacao-dinamica
    Complexidade: O(n²)
*/

#include <iostream>
using namespace std;

int main() {

    int l, c, m, n, i, j, k;
    int a[1000][1000], b[1000][1000];
    
    cin >> l >> c >> m >> n;
    
    for (i = 0; i < l; i++)
        for (j = 0; j < c; j++)
            cin >> a[i][j];
            
    for (i = 0; i < l; i++) {
        b[i][0] = 0;
       
        for (j = 0; j < n; j++)
            b[i][0] += a[i][j];
            
        for (j = 1; j < c-n+1; j++)
            b[i][j] = b[i][j-1] + a[i][j+n-1] - a[i][j-1];
    }
    
    for (j = 0; j < c-n+1; j++) {
        a[0][j] = 0;
        
        for (i = 0; i < m; i++)
            a[0][j] += b[i][j];
        
        for (i = 1; i < l-m+1; i++) 
            a[i][j] = a[i-1][j] + b[i+m-1][j] - b[i-1][j];
    }
    
    int max = 0;
    for (i = 0; i < l-m+1; i++)
        for (j = 0; j < c-n+1; j++)
            if ( a[i][j] > max )
                max = a[i][j];
                
    cout << max;

    return 0;
}
