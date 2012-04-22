
/*
    Olimpíada Brasileira de Informática
    2001
    Problema: Dominó
    
    Data de submissão: 12/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: grafos, conectividade, busca-em-profundidade
    Complexidade: O(1)
*/

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

/*
    Comentários sobre a solução:
    
    Esse é um dos problemas de grafos mais interessantes da OBI. A solução é 
simples, mas temos que pensar bastante para chegarmos a ela.
    A primeira coisa óbvia é que temos que manter um contador pra quantas vezes
aparece o valor X numa pedra (chamemos 'grau'[1]). Só pode haver 0 ou 2 pedras 
grau ímpar. O motivo? Para uma pedra conectar-se a outra, é necessária a 
aparição de um número duas vezes (fazendo isso para todas as pedras, chega-se
à conclusão do grau par). A única exceção são o caso das pontas, que
não precisam se conectar a ninguém, logo não interessando se tem grau par
ou ímpar.
    Adiantando logo a solução:
    1) Verificar se o número de valores com grau ímpar é 0 ou 2.
    2) Verificar se o grafo é conexo.
    Na primeira vez que vi o problema, eu fiquei me preocupando em como 
representar o grafo com as pedras. Como tratar o caso de pedras repetidas?
No caso de pedras repetidas, a primeira verificação mata. (Pense um pouco sobre
isso). Depois de eliminar os duplicados, basta então verificar se o grafo
é conexo.

[1]: Grau entre aspas porque essa definição não é estritamente equivalente ao 
    conceito real de grau de um vértice.
*/

bool pedra[7][7];
int grau[7];
bool visitado[7];

/* 
    O ideal seria uma visita não-recursiva, entretanto, o número de 
    vértices é pequeno demais para nos preocuparmos com isso.
*/

void visita(int p) {
    visitado[p] = true;
        
    for (int i = 0; i < 7; i++)
        if ( pedra[p][i] && !visitado[i] ) 
            visita(i);
}

bool conexo() {
    int i;
    
    for (i = 0; grau[i] == 0; i++);
    
    visita(i);
    
    for (i = 0; i < 7; i++)
        if ( grau[i] > 0 && !visitado[i] )
            return false;
            
    return true;
}

int main() {
    int i, n, u, v, contaImpares, teste=1;

    while (true) {
        cin >> n;
        
        if (n == 0) break;
        
        printf("Teste %d\n", teste++);
        
        memset(grau, 0, sizeof(grau));
        memset(visitado, false, sizeof(visitado));
        memset(pedra, false, sizeof(pedra));
        
        for (i = 0; i < n; i++) {
            cin >> u >> v;       
            grau[u]++; grau[v]++;
            pedra[u][v] = pedra[v][u] = true;
        }
        
        for (contaImpares = i = 0; i < 7; i++)
            if ( grau[i] % 2 == 1 ) 
                contaImpares++;
            
        if ( (contaImpares != 0 && contaImpares != 2) || !conexo() )
            printf("nao\n\n");
        else
            printf("sim\n\n");
    }

    return 0;
}
