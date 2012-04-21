
/*
    Olimpíada Brasileira de Informática
    Nível 2, Fase 1, 2006
    Problema: Museu
    
    Data de submissão: 20/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: grafos, ciclo-minimo, floyd-warshall
    Complexidade: O(n³)
*/

#include <iostream>
using namespace std;

int UNDEFINED = 1 << 28;

int main() {

    int s, c, i, j, k, u, v, t;
    int tsala[1000], tfinal[1000][1000];
    
    cin >> s >> c;
    
    for (i = 0; i < s; i++) {
        cin >> tsala[i];
        
        for (j = 0; j < s; j++)
            tfinal[i][j] = UNDEFINED;
    }  
    
    for (i = 0; i < c; i++) {
        cin >> u >> v >> t;
        u--; v--;
        // adiciona o peso do vértice em cada aresta de entrada
        tfinal[u][v] = t + tsala[v];
    }
    
    for (k = 0; k < s; k++)
        for (i = 0; i < s; i++)
            for (j = 0; j < s; j++)
                tfinal[i][j] = min(tfinal[i][j], tfinal[i][k] + tfinal[k][j]);
                
    // algoritmo lindo, prova fácil por contradição
    // deixo a demonstração como exercício, risos
    int m = UNDEFINED;
    for (i = 0; i < s; i++)
        for (j = 0; j < s; j++)
            m = min(m, tfinal[i][j] + tfinal[j][i]);
               
    cout << m;

    return 0;
}
