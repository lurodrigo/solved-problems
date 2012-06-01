
/*
    Olimpíada Brasileira de Informática
    1999
    Problema: Projeto Genoma
    
    Data de submissão: 01/06/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: string-matching, kmp
    Complexidade: O(m + n)
*/

#include <iostream>
#include <cstdio>
using namespace std;

char p[15002], t[15002];
int pref[15002];
int m, n;

void compute_prefix() {
    for (int k = 0, q = 2; q <= m; q++) {
        while ( k > 0 && p[k+1] != p[q] )
            k = pref[k];
        if ( p[k+1] == p[q] )
            k++;
        pref[q] = k;
    }
}

void kmp() {
    int counter = 0;
    
    compute_prefix();
    for (int q = 0, i = 1; i <= n; i++) {
        while ( q > 0 && p[q+1] != t[i] )
            q = pref[q];
        if ( p[q+1] == t[i] )
            q++;
        
        if ( q == m ) {
            q = pref[q];
            printf("%d ", i+1 - m);
            counter++;
        }
    }
    
    if ( counter == 0 )
        printf("0");
}

char comp(char base) {
    switch (base) {
    case 'A': return 'T';
    case 'T': return 'A';
    case 'C': return 'G';
    default: return 'C';
    }
}

int main() {
    int teste = 1;
    
    while (true) {
        cin >> m >> n;
        
        if ( m == 0 ) break;
        
        cin >> &p[1] >> &t[1];
         
        printf("Teste %d\n", teste++);
        printf("ocorrencia direta: ");
        
        kmp();
        
        for (int i = 1; i <= m/2; i++) {
            char aux = comp(p[i]);
            p[i] = comp(p[m+1-i]);
            p[m+1-i] = aux;
        } 
        
        printf("\nocorrencia complementar inversa: ");
        kmp();
        
        printf("\n\n");
    }

    return 0;
}
