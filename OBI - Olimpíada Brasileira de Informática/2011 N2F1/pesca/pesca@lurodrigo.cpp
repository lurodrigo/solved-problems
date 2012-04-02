/*
    Olimpíada Brasileira de Informática
    Nível 2, Fase 1, 2011
    Problema: O mar não está pra peixe
    
    Data de submissão: 02/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: matrizes
    Complexidade: O(1)
*/

#include <iostream>
using namespace std;

bool mar[100][100];

int main() {
    int n, x1, x2, y1, y2, i, j, count = 0;
    
    cin >> n;
    
    while (n--) {
        cin >> x1 >> x2 >> y1 >> y2;
        x1--; x2--; y1--; y2--;
        
        for (i = x1; i < x2; i++)
            for (j = y1; j < y2; j++)
                if ( !mar[i][j] ) {
                    mar[i][j] = true;
                    count++;
                }
    }
    
    cout << count;
    
    return 0;
}
