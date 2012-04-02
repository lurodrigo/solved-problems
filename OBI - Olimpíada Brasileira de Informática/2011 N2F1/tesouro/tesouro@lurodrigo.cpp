
/*
    Olimpíada Brasileira de Informática
    Nível 2, Fase 1, 2011
    Problema: Caça ao tesouro
    
    Data de submissão: 02/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: Matrizes
    Complexidade: O(1)
*/

#include <iostream>
using namespace std;

bool mapa[100][100];

inline int abs(int x) {
    return (x >= 0) ? x : -x;
}

int main() {

    int n, k, x, y, d, i, j, count = 0;
    
    cin >> n >> k;
    
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            mapa[i][j] = true;
    
    while (k--) {
        cin >> x >> y >> d;
        
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if ( !(abs(i-x) + abs(j-y) == d) ) {
                    mapa[i][j] = false;
                } 
    }
    
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if ( mapa[i][j] ) {
                count++;
                x = i;
                y = j;
            }
      
    if (count == 1)
        cout << x << " " << y;
    else
        cout << "-1 -1";
    
    return 0;
}
