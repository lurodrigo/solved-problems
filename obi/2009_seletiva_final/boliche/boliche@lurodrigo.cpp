
/*
    Olimpíada Brasileira de Informática
    Seletiva para a IOI, Teste Final, 2009
    Problema: Boliche
    
    Data de submissão: 29/05/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: ad-hoc
    Complexidade: O(1)
*/

#include <iostream>
using namespace std;

enum Tipo { NORMAL, SPARE, STRIKE };
 
int to_int(char c) {
    return (c == '-') ? 0 : c-'0';
}
 
int main() {

    char jogada[5];
    int bola[21], tipo[21];
    int i, j, k, emPe, total = 0;
    
    for (i = k = 0; i < 10; i++) {
        cin >> jogada;
        
        for (j = 0, emPe = 10; jogada[j]; j++, k++) {
            if ( jogada[j] == 'X' ) {
                bola[k] = 10;
                tipo[k] = STRIKE;
                emPe = 10;
            } else if ( jogada[j] == '/' ) {
                bola[k] = emPe;
                tipo[k] = SPARE;
                emPe = 10;
            } else {
                bola[k] = to_int(jogada[j]);
                tipo[k] = NORMAL;
                emPe -= to_int(jogada[j]);
            }
            
            if ( i == 9 )
                tipo[k] = NORMAL;
        }
    }
    
    for (i = 0; i < k; total += bola[i], i++)
        for (j = 0; j < tipo[i]; j++)
            bola[i] += bola[i + j + 1];

    cout << total;      
            
    return 0;
}
