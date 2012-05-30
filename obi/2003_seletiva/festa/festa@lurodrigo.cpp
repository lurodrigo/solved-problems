
/*
    Olimpíada Brasileira de Informática
    Seletiva para a IOI, 2003
    Problema: Festa Junina
    
    Data de submissão: 28/05/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: backtracking, np-hard
    Complexidade: O((n + m)*2^n) (upper bound fraco)
    
    Esse problema é conhecimento como maximum independent set, e é NP-hard.
    Consiste em, dado um grafo, escolher o maior subset de vértices possíveis
    tais que nenhuma aresta seja compartilha por dois vértices desse set. 
    Posto de outra forma, o maior subset de vértices tais que nenhum vértice
    tem aresta pra outro vértice do mesmo subset.
*/

#include <iostream>
#include <cstdio>
using namespace std;

bool exists[20]; 
int g[20][20], ng[20], lexists[21];

bool verify(int k) {
    for (int i = 0; i < k; i++)
        for (int j = 0; j < ng[lexists[i]]; j++)
            if ( exists[g[lexists[i]][j]] )
                return false;
    
    return true;
}

int maximum;
void backtrack(int n, int k) {
    if ( verify(k) ) {
        maximum = max(maximum, k);
    } else
        return;
    
    for (int i = lexists[max(0, k-1)] + 1; i < n; i++) {
        lexists[k] = i;
        exists[i] = true;
        backtrack(n, k + 1);
        exists[i] = false;
    }
}

int main() {
    int n, i, j, teste = 1;
    
    while (true) {
        cin >> n;
        
        if ( n == 0 ) break;
        
        for (i = 0; i < n; i++) {
            exists[i] = false;
            for (j = 0; j < n; j++)
                g[i][j] = true;
        }
        
        for (i = 0; i < n; i++)
            for (ng[i] = 0; ; g[i][ng[i]]--, ng[i]++) {
                cin >> g[i][ng[i]];
                if ( g[i][ng[i]] == 0 ) break;
            }
        
        maximum = 0;
        lexists[0] = -1;
        backtrack(n, 0);
        printf("Teste %d\n%d\n\n", teste++, maximum); 
    }

    return 0;
}
