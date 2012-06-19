
/*
    Olimpíada Brasileira de Informática
    2001, Seletiva IOI
    Problema: Clipe
    
    Data de submissão: 09/05/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: algoritmos-gulosos
    Complexidade: O(n log n)
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Clipe {
    int start, finish;
} clipes[10000];

bool comp(Clipe a, Clipe b) {
    return a.finish < b.finish;
}

int main() {

    int i, j, c, n, s, d, t = 1;
    
    while (true) {
        cin >> n;
        
        if ( n == 0 ) break;
        
        for (i = 0; i < n; i++) {
            cin >> s >> d;
            clipes[i].start = s;
            clipes[i].finish = s + d-1;
        }
        
        sort(clipes, clipes+n, comp);
        
        c = 1; j = 0;
        for (i = 1; i < n; i++)
            if ( clipes[i].start > clipes[j].finish ) {
                j = i;
                c++;
            }
        
        printf("Teste %d\n%d\n\n", t++, c);
    }

    return 0;
}
