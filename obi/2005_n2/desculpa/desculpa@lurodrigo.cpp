
/*
    Olimpíada Brasileira de Informática
    2005, Nível 2
    Problema: Pedido de desculpas
    
    Data de submissão: 12/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: programacao-dinamica, knapsack
    Complexidade: O(nt) (por caso de teste)
    
*/

#include <iostream>
using namespace std;

int opt[1001];

int knapsack(int len[], int sorry[], int c, int f) {
    int i, j;
    
    for (i = 0; i <= c; i++)
        opt[i] = 0;
   
    for (j = 0; j < f; j++)
        for (i = c; i >= len[j]; i--)
            opt[i] = max(max(opt[i], opt[i-1]), opt[i-len[j]] + sorry[j]);
    
    return opt[c];
}

int main() {

    int c, f, i, t = 1, len[201], sorry[201];
    
    while (true) {
        cin >> c >> f;
        
        if ( c == 0 && f == 0 )
            break;
            
        cout << "Teste " << t++ << endl;
        
        for (i = 0; i < f; i++)
            cin >> len[i] >> sorry[i];
            
        cout << knapsack(len, sorry, c, f) << "\n\n";
    }

    return 0;
}
