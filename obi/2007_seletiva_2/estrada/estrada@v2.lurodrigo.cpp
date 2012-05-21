
/*
    Olimpíada Brasileira de Informática
    Seletiva para a IOI, Teste II, 2007
    Problema: Estrada Romana
    
    Data de submissão: 17/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: programacao-dinamica, algoritmos-gulosos, arvore-custo-minimo, prim
    Complexidade: O(n²)
    
    Solução 1: Usa o algoritmo de Prim como base
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int undef = 1 << 20;

struct Node {
    bool visited;
    int key, dist[250];
} cities[250];

void init(int n, int o) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cities[i].dist[j] = undef;
        cities[i].visited = false;
        cities[i].key = undef;
    }
    
    cities[o].key = 0;
}

int extract_min(int n) {
    int i, min;
    
    for (min = 0; cities[min].visited; min++);
    for (i = min+1; i < n; i++)
        if ( cities[i].key < cities[min].key )
            min = i;
            
    cities[min].visited = true;
    return min;
}

int countWays[101];

int main() {

    int n, p, e, i, j, u, v, l, time = 0;
    
    cin >> n >> p >> e;

    countWays[0] = 1;
    for (j = 1; j <= p; j++) {
        cin >> l;
        for (i = l; i <= 100; i++)
            countWays[i] += countWays[i-l];
    }
    
    for (i = 0; i < e; i++) {
        cin >> u >> v >> l;
        u--; v--;
        if ( countWays[l] > 0 )
            cities[u].dist[v] = cities[v].dist[u] = countWays[l];
    }
    
    init(n, 0);
    for (i = 0; i < n; i++) {
        u = extract_min(n);
        
        if ( cities[u].key >= undef ) {
            time = -1;
            break;
        }
            
        time += cities[u].key;
        
        for (j = 0; j < n; j++) {
            cities[j].key = min(cities[j].key, cities[u].dist[j]);
            cout << cities[i].key << " ";
        }
    }

    cout << time;

    return 0;
}