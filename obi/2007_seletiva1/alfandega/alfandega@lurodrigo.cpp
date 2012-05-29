
/*
    Olimpíada Brasileira de Informática
    Seletiva para a IOI, Teste I, 2007
    Problema: Alfândega
    
    Data de submissão: 29/05/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: programacao-dinamica
    Complexidade: O(n³)
*/

#include <iostream>
#include <cstdio>
using namespace std;

const int MAX_COTA = 501;
const int MAX_N = 100;

bool possivel[2*MAX_COTA][2*MAX_COTA];
struct Par {
    int set1, set2;
    Par(int a = 0, int b = 0) : set1(a), set2(b) {}
} pares[4*MAX_COTA*MAX_COTA];

int cota, aliquota, total;
int preco[MAX_N];

int imposto(int set1, int set2) {
    return max(0, set1-cota) + max(0, set2 - cota) + max(0, total - set1 - set2 - cota);
}

void mostra(int imp) {
    int val = aliquota * imp;
    // trick para evitar usar aritmética de ponto flutuante
    printf("%d.%02d\n", val / 100, val % 100);
}

int main() {

    int n, i, j, k, num_pares, set1, set2, menor = 1 << 28;
    
    cin >> n >> cota >> aliquota;
    
    for (i = 0; i < n; i++) {
        cin >> preco[i];
        total += preco[i];
    }
    
    possivel[0][0] = true;
    pares[0] = Par(0, 0);
    num_pares = 1;
    
    // a cada item, testa todas as possibilidades de custo que podem 
    // ser formadas
    for (i = 0; i < n; i++) {
        for (j = 0, k = num_pares; j < k; j++) {
            // testa pondo item no primeiro set
            set1 = min(pares[j].set1 + preco[i], pares[j].set2);
            set2 = max(pares[j].set1 + preco[i], pares[j].set2);
            
            if ( set2 < 2*cota && !possivel[set1][set2] ) {
                possivel[set1][set2] = true;
                pares[num_pares++] = Par(set1, set2);
                menor = min(menor, imposto(set1, set2));
            }
            
            // testa pondo item no segundo set
            set1 = min(pares[j].set1, pares[j].set2 + preco[i]);
            set2 = max(pares[j].set1, pares[j].set2 + preco[i]);
            
            if ( set2 < 2*cota && !possivel[set1][set2] ) {
                possivel[set1][set2] = true;
                pares[num_pares++] = Par(set1, set2);
                menor = min(menor, imposto(set1, set2));
            }
        }
    }
    
    mostra(menor);
    
    return 0;
}
