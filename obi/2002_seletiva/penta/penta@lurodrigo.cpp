
/*
    Olimpíada Brasileira de Informática
    Seletiva para a IOI, 2002
    Problema: Penta!
    
    Data de submissão: 22/05/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: gulosos
    Complexidade: O(n)
*/

#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

const int UNDEF = 1 << 28;
int conta[24];
set<int> palanque;

int findmin() {
    int m = 0;
    
    for (set<int>::iterator it = palanque.begin(); it != palanque.end(); it++)
        if ( conta[*it] < conta[m] )
            m = *it;
            
    return m;
}

int main() {
    
    int n, c, i, x, trocas, teste = 1;
    int jog[10000];
    
    while (true) {
        cin >> n >> c;
        
        if ( n == 0 ) break;
        
        trocas = 0;
        palanque.clear();
        fill(conta, conta + 24, UNDEF);
        
        for (i = 0; i < n; i++) {
            cin >> jog[i];
            
            if ( conta[jog[i]] == UNDEF )
                conta[jog[i]] = 0;
                
            conta[jog[i]]++;
        }
       
        for (i = 0; i < n; i++) {
            if ( palanque.size() < c )
                palanque.insert(jog[i]);
            else if ( palanque.find(jog[i]) == palanque.end() ) {
                palanque.erase(findmin());        
                palanque.insert(jog[i]);
                trocas++;
            }
            
            conta[jog[i]]--;
        }
        
        printf("Teste %d\n%d\n\n", teste++, trocas);
    }
    
    return 0;
}
