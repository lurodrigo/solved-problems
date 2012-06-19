
/*
    Olimpíada Brasileira de Informática
    Seletiva IOI 2008, Teste Final
    Problema: Trapézio
    
    Data de submissão: 17/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: ordenação
    Complexidade: O(n log n)
    
    Obs: Se você estiver interessado no problema original (saber o número
    de pessoas num empilhamento ótimo), pesquise sobre o problema Weights
    and Measures. Sua solução envolve uma programação dinâmica de complexidade
    O(n²). Entretanto, esse problema é sutilmente diferente, pois é necessário
    que TODOS os trapezistas sejam empilhados. Isso nos permite fazer umas
    assumptions que reduzem a complexidade da solução.
*/

#include <iostream>
#include <algorithm>
using namespace std;

struct Trapezist {
    int weight, strength, id;
} trap[10000];

bool comp(Trapezist a, Trapezist b) {
    if ( a.weight + a.strength != a.weight + a.strength  )
        return a.weight + a.strength < a.weight + a.strength;
    else if ( a.weight != b.weight )
        return a.weight < b.weight;
    else
        return a.id > b.id; 
}

int main() {

    int i, n, acc=0;
    bool possivel = true;
    
    cin >> n;
    
    for (i = 0; i < n; i++) {
        cin >> trap[i].weight >> trap[i].strength;
        trap[i].id = i+1;
    }
        
    sort(trap, trap + n, comp);
    
    for (i = 0; i < n; acc += trap[i].weight, i++)
        if ( acc > trap[i].strength ) {
            possivel = false;
            break;
        }

    if ( possivel )
        for (i = n-1; i >= 0; i--)
            cout << trap[i].id << endl;
    else
        cout << "IMPOSSIVEL\n";

    return 0;
}
