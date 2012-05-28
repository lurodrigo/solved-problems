
/*
    Olimpíada Brasileira de Informática
    Seletiva IOI 2006
    Problema: Pérolas
    
    Data de submissão: 13/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: grafos, busca-em-largura
    Complexidade: O(n)
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 10000;
int aux[] = {0, 6, 4, 5, 2, 3, 1};

int max_without(int i, int j) {
    int x[] = {0, 1, 2, 3, 4, 5, 6};
    x[i] = x[j] = 0;
    return *max_element(x, x + 7);
}

int comp[MAX_N][7], s[MAX_N][7];

int main() {
    int n, i, j, k;
    int v[7];
    cin >> n;
    
    for (i = 0; i < n; i++) {
        for (j = 1; j <= 6; j++) 
            cin >> v[j];
        
        for (j = 1; j <= 6; j++)
            comp[i][v[aux[j]]] = v[j];    
    }

    for (j = 1; j <= 6; j++) 
        s[0][j] = max_without(j, comp[0][j]);
        
    for (i = 1; i < n; i++) 
        for (j = 1; j <= 6; j++)
            s[i][j] = s[i-1][comp[i][j]] + max_without(j, comp[i][j]);
            
    cout << *max_element(s[n-1], s[n-1]+7);

    return 0;
}
