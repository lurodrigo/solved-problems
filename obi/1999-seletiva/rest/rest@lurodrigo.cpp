
/*
    Olimpíada Brasileira de Informática
    Seletiva para a IOI, 1999
    Problema: Restaurante
    
    Data de submissão: 13/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: ordenação, simulação
    Complexidade: O(n log n)
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 5001;

int main() {

    int i, j, maximo, conta, n, teste = 1;
    int entrada[MAX_N], saida[MAX_N];
    
    while (true) {
        cin >> n;
        
        if ( n == 0 ) break;
        
        for (i = 0; i < n; i++)
            cin >> entrada[i];
            
        for (i = 0; i < n; i++)
            cin >> saida[i];
        
        entrada[n] = saida[n] = 100000;
        sort(saida, saida+n);
        
        maximo = conta = 0;
        for (i = 0, j = 0; i < n || j < n;) {
            if ( entrada[i] < saida[j] ) {
                conta++; 
                i++;
            } else {
                conta--;
                j++;
            }
            
            maximo = max(maximo, conta);
        }
        
        printf("Teste %d\npessoas: %d\n\n", teste++, maximo);
    }

    return 0;
}