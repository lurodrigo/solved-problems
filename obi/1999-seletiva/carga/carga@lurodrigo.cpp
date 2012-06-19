
/*
    Olimpíada Brasileira de Informática
    1999, Seletiva IOI
    Problema: Carga pesada
    
    Data de submissão: 12/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: grafos, floyd-warshall
    Complexidade: O(n**3)
    
    To-do: provar a corretude do algoritmo
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    
    int maxalt[100][100];
    int i, j, k, x, y, u, v, h, nmin, nmax, teste=1;
    
    while (true) {
        cin >> x >> y;
        
        if ( x == 0 && y == 0 )
            break;
        x--; y--;
            
        for (i = 0; i < 100; i++)
            for (j = 0; j < 100; j++)
                maxalt[i][j] = 0;
            
        nmin = 100;   
        nmax = 0;
        while (true) {
            cin >> u >> v >> h;
            
            if ( u == 0 && v == 0 && h == 0 )
                break;
                
            u--; v--;
                   
            if ( u > nmax ) nmax = u;
            else if ( u < nmin ) nmin = u;
            if ( v > nmax ) nmax = v;
            else if ( v < nmin ) nmin = v;
            
            maxalt[u][v] = max(maxalt[u][v], h);
        }
        
        // printf("n = %d\n", n);
        
        for (k = nmin; k <= nmax; k++)
            for (i = nmin; i <= nmax; i++)
                for (j = nmin; j <= nmax; j++)
                    maxalt[i][j] = max(min(maxalt[i][k], maxalt[k][j]), 
                                       maxalt[i][j]);
                                       
        printf("Teste %d\naltura maxima: %d\n\n", teste++, maxalt[x][y]);
                        
    }
    
    return 0;
}
