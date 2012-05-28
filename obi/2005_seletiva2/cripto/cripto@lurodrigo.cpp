
/*
    Olimpíada Brasileira de Informática
    2005, Seletiva IOI, Teste I
    Problema: Programação dinâmica
    
    Data de submissão: 29/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: programacao-dinamica
    Complexidade: O(t)  
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int NLETRAS = 128;
struct Letra {
    char letra;
    int conta;
} letras[NLETRAS];

char corresponde[NLETRAS];

bool comp(Letra a, Letra b) {
    if ( a.conta != b.conta )
        return a.conta > b.conta;
    else
        return a.letra < b.letra;
}

void read(char *s, int len) {
    for (int i = 0; i < len; i++)
        s[i] = getchar();
    s[len] = 0;
    getchar();
}

int main() {

    char sf[27], st[10001];
    int i, j, f, t, teste = 1;
   
    while (true) {
        cin >> t >> f;
  
        if ( f == 0 ) break;
        
        for (i = 0; i < NLETRAS; i++) {
            letras[i].letra = i;
            letras[i].conta = 0;
        }
        
        getchar();
        read(sf, f);
        read(st, t);
       
        for (i = 0; i < t; i++)
            letras[st[i]].conta++;  
        letras[' '].conta = -1;
       
        sort(letras, letras + NLETRAS, comp);
        
        for (i = 0; i < f; i++)
            corresponde[letras[i].letra] = sf[i];
        corresponde[' '] = ' ';
        
        printf("Teste %d\n", teste++);
        for (i = 0; i < t; i++)
            putchar(corresponde[st[i]]);
        printf("\n\n");
    }

    return 0;
}
