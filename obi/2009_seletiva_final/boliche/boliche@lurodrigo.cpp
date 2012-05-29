
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
#include <string>
using namespace std;
using std::string;

enum Tipo { NORMAL, SPARE, STRIKE };
 
int main() {

    string jogada;
    int bola[21], tipo[21];
    int i, j, k, emPe, total = 0;
    
    for (i = k = 0; i < 10; i++) {
        cin >> jogada;
        
        for (j = 0, emPe = 10; j < jogada.length(); j++, k++) {
            if ( jogada[j] == '-' ) {
                bola[k] = 0;
                tipo[k] = NORMAL;
            } else if ( jogada[j] == 'X' ) {
                bola[k] = 10;
                tipo[k] = STRIKE;
                emPe = 10;
            } else if ( jogada[j] == '/' ) {
                bola[k] = emPe;
                tipo[k] = SPARE;
                emPe = 10;
            } else {
                bola[k] = jogada[j] - '0';
                tipo[k] = NORMAL;
                emPe -= jogada[j] - '0';
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
