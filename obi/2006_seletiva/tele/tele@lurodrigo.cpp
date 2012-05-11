
/*
    Olimpíada Brasileira de Informática
    2006, Seletiva IOI
    Problema: Teletransporte
    
    Data de submissão: 10/05/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: grafos, floyd-warshall
    Complexidade: O(n³)
*/

#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

const int UNDEF = 1 << 28;

struct Pair {
    int i, j;
    
    Pair(int a=0, int b=0) {
        i = a;
        j = b;
    }
    
};

bool operator<(Pair a, Pair b) {
    if ( a.i != b.i )
        return a.i < b.i;
    else
        return a.j < b.j;
}

int main() {

    int d[200][200];  
    set<Pair> possible, aux;
    int n, m, i, j, k, u, v;
      
    cin >> n >> m;
    
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            d[i][j] = UNDEF;
    for (i = 0; i < n; i++)
        d[i][i] = 0;
        
    for (i = 0; i < m; i++) {
        cin >> u >> v >> k;
        u--; v--;
        d[u][v] = d[v][u] = min(d[u][v], k);
    }
    
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++) 
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
               
    cin >> m >> u >> v >> k;
    u--; v--;
    
    for (i = 0; i < n; i++)
        for (j = i+1; j < n; j++)
            if ( min(d[u][v], min(d[u][i] + d[j][v], d[u][j] + d[i][v])) == k )
                possible.insert(Pair(i, j));
      
    set<Pair>::iterator it;          
    while ( possible.size() > 1 ) {
        cin >> u >> v >> k;
        
        u--; v--;
        for (it = possible.begin(); it != possible.end(); it++)
            if ( min(d[u][v], min(d[u][it->i] + d[it->j][v], d[u][it->j] + d[it->i][v])) != k )
                aux.insert(*it);
                
        for (it = aux.begin(); it != aux.end(); it++)
            possible.erase(*it);
        
        aux.clear();
    }
    
    Pair result = *possible.begin();
    printf("%d %d\n", result.i+1, result.j+1);

    return 0;
}
