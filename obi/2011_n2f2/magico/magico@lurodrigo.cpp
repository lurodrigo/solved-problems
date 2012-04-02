
/*
    Olimpíada Brasileira de Informática
    Nível 2, Fase 2, 2011
    Problema: Quadrado Mágico
    
    Data de submissão: 02/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: aritmética, matrizes
    Complexidade: O(n²)
*/

#include <iostream>
using namespace std;

const int MAX = 1001;
int diag;
int col[MAX], row[MAX];
bool usado[1000001];

int main() {

    int n, i, j, x;
    bool eMagico = true;
    
    cin >> n;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> x;
            
            if (x < 1 || x > 1000000 || usado[x]) {
                eMagico = false;
            } else {
                usado[x] = true;
                
                row[i] += x;
                col[j] += x;
                
                if ( i == j )
                    diag += x;
            }
        }
    }
    
    for (i = 0; i < n; i++)
        eMagico &= (col[i] == diag) && (row[i] == diag);
        
    if ( eMagico )
        cout << diag;
    else
        cout << 0;

    return 0;
}

