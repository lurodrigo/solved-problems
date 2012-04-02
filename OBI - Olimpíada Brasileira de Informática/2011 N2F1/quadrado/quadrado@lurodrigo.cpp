/*
    Olimpíada Brasileira de Informática
    Nível 2, Fase 1, 2011
    Problema: Quadrado Aritmético
    
    Data de submissão: 30/03/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: ad-hoc, aritmética, matrizes
    Complexidade: O(n²)
*/

#include <iostream>
using namespace std;

int main() {

    int n, s, sr, i, j;
    
    cin >> n >> s;
    sr = (n+1)*n*(n-1) / 2;

    if ( s > sr ) {
        for (i = 0; i < n-1; i++) {
            for (j = 0; j < n; j++)
                cout << i*n + j << " ";
            cout << endl;
        }
        
        for (j = 0; j < n; j++) {
            cout << n*(n-1) + j + s - sr << " ";
        }
    }
    else {
        for (j = 0; j < n; j++) {
            cout << j + s-sr << " ";
        }
        
        for (i = 1; i < n; i++) {
            cout << endl;
            
            for (j = 0; j < n; j++)
                cout << i*n + j << " ";
        }
       
    }
     
    return 0; 
}
