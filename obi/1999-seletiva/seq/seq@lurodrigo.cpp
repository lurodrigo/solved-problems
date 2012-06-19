
/*
    Olimpíada Brasileira de Informática
    1999, Seletiva para a IOI
    Problema: Sequências
    
    Data de submissão: 28/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: programacao-dinamica
    Complexidade: O(n³)  
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool h[200][200];

bool isH(char s[], int len) {
    int i, j, k, l;
    
    for (i = 0; i < len; i++)
        for (j = 0; j < len; j++)
            h[i][j] = false;
    
    for (i = 0; i < len; i++)
        h[i][i] = (s[i] == '0');
        
    for (l = 2; l <= len; l++)
        for (i = 0, j = i+l-1; j < len; i++, j++) {
            if ( s[i] != '1' ) 
                continue;
                
            for (k = i+1; k+1 <= j; k++)
                if ( h[i+1][k] && h[k+1][j] ) {
                    h[i][j] = true;
                    break;
                }
        }

    return h[0][len-1];
}

int main() {
    char s[202];
    int teste = 1;
    
    while (true) {
        scanf("%s", s);
        if ( strcmp(s, "#") == 0 ) 
            break;
            
        printf("Teste %d\n%s\n\n", teste++, 
            (isH(s, strlen(s)-1) ? "sim" : "nao"));
    }
    

    return 0;
}

