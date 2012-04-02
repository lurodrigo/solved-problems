
/*
    Olimpíada Brasileira de Informática
    Nível 2, Fase 1, 2012
    Problema: Frequência
    
    Data de submissão: 31/03/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: vetores, elementos-duplicados
    Complexidade: O(n)
*/

#include <cstdio>

bool presente[1000001];

int main() {

    int i, n, v, conta = 0;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &v);
        
        if ( !presente[v] ) {
            presente[v] = true;
            conta++;
        }
    }
    
    printf("%d", conta);

    return 0;
}
