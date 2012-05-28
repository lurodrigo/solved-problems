
/*
    Olimpíada Brasileira de Informática
    Nível 2, Fase 1, 2006
    Problema: Truco
    
    Data de submissão: 20/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: ad-hoc, comparacoes
    Complexidade: O(n)

*/

#include <iostream>
#include <cstdio>
using namespace std;

int map(int n) {
    /* Mapeia os valores de acordo com o valor simbólico:
        4 => 0; 5 => 1; 6 => 2; 7=> 3;
        Q => 7; J => 8; K => 9;
        1 => 10; 2 => 12; 3=> 13 */
        
    if ( n == 11 ) return 8;
    if ( n == 12 ) return 7;
    return (n + 9) % 13;
}

int main() {

    int n;
    int i, j, a[3], b[3], count_a = 0, points_a;
    
    cin >> n;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < 3; j++) cin >> a[j];
        for (j = 0; j < 3; j++) cin >> b[j];
        for (points_a = j = 0; j < 3; j++) 
            if ( map(a[j]) >= map(b[j]) )
                points_a++;
                
        if ( points_a >= 2 ) 
            count_a++;
    }
    
    printf("%d %d", count_a, n - count_a);
    
    return 0;
}
