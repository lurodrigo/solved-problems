
/*
    Olimpíada Brasileira de Informática
    2005, Seletiva IOI, Teste I
    Problema: Programação dinâmica
    
    Data de submissão: 29/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: programacao-dinamica
    Complexidade: O(m*n)  
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_M = 1000;

int main() {

    int i, j, m, n, teste=1;
    int v[MAX_M], left[MAX_M], right[MAX_M], nleft[MAX_M], nright[MAX_M];
    
    while (true) {
        cin >> n >> m;
        
        if ( m == 0 ) break;
        
        fill(left, left + m, 0);
        fill(right, right + m, - (1 << 28));
        
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++)
                cin >> v[j];   
                
            nleft[0] = max(left[0], right[0]) + v[0];
            for (j = 1; j < m; j++)
                nleft[j] = v[j] + max(max(left[j], right[j]), nleft[j-1]);
            
            nright[m-1] = max((i > 0) ? left[m-1] : right[m-1], right[m-1]) + 
                v[m-1];
            for (j = m-2; j >= 0; j--)
                nright[j] = v[j] + max(max(left[j], right[j]), nright[j+1]);
                
            copy(nleft, nleft+m, left);
            copy(nright, nright+m, right);
        }
        
        printf("Teste %d\n%d\n\n", teste++, max(left[m-1], right[m-1]));
    }

    return 0;
}
