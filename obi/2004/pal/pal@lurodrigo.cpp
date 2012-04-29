/*
    Olimpíada Brasileira de Informática
    2004
    Problema: Palíndrome
    
    Data de submissão: 28/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: programacao-dinamica
    Complexidade: O(n²)  
*/

#include <iostream>
#include <cstdio>
using namespace std;

bool p[2000][2000];
void build(char s[], int len) {
    int i, j, l;
    
    for (i = 0; i < len; i++)
        p[i][i] = true;
    for (i = 0; i+1 < len; i++)
        p[i][i+1] = (s[i] == s[i+1]);
        
    for (l = 3; l <= len; l++)
        for (i = 0; i+l-1 < len; i++)
            p[i][i+l-1] = (s[i] == s[i+l-1]) && p[i+1][i+l-2];
}

int m[2000];
int min_pal(char s[], int len) {
    m[0] = 1;
    
    for (int i = 1; i < len; i++) {
        m[i] = (p[0][i]) ? 1 : i+1;
        for (int j = 1; j <= i; j++) 
            if ( p[j][i] )
                m[i] = min(m[i], m[j-1]+1);
    }
    
    return m[len-1];
}

int main() {

    int i, j, l, teste = 1;
    char s[2001];

    while (true) {
        cin >> l;
        
        if ( l == 0 )
            break;
            
        cin >> s;
        
        build(s, l);
        printf("Teste %d\n%d\n\n", teste++, min_pal(s, l));
    }

    return 0;
}
