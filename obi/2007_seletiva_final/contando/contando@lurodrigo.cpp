
/*
    Olimpíada Brasileira de Informática
    Seletiva IOI 2007, Teste Final
    Problema: Contando Palíndromes
    
    Data de submissão: 17/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: programacao-dinamica, strings, combinatorias
    Complexidade: O(i)
*/

#include <iostream>
using namespace std;

typedef long long int llong;

const llong TEN_18 = 1000000000000000000;

char alphabet[27];
int n;
llong count[101];

void init(int l) {
    count[0] = 1;
    count[1] = n;
    for (int i = 2; i <= l; i++)
        if ( count[i-2] <= TEN_18 )
            count[i] = n * count[i-2];
        else
            count[i] = TEN_18;
}

void print(int l, llong i) {
    if ( l == 0 ) 
        return;
        
    if ( l == 1 ) {
        cout << alphabet[i];
        return;
    }

    int c = i / count[l-2];
    cout << alphabet[c];
    print(l-2, i % count[l-2]);
    cout << alphabet[c];
}

int main() {
    int l;
    llong i;
    
    cin >> n >> alphabet >> l >> i;
    init(l);
    print(l, i-1);

    return 0;
}
