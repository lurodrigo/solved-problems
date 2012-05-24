
/*
    Olimpíada Brasileira de Informática
    Seletiva para a IOI, Teste III, 2008
    Problema: Viagem de volta ao mundo
    
    Data de submissão: 24/05/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: programacao-dinamica
    Complexidade: O(n²t)
 
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct City {
    int lat, lon;
} cities[501];

int m[501][501];

bool comp(City a, City b) {
    if ( a.lon != b.lon )
        return a.lon < b.lon;
    else
        return a.lat < b.lat;
}

int main() {

    int i, j, k, n, t, diff;
    
    cin >> n >> t;
    
    cin >> cities[0].lat >> cities[0].lon;
    for (i = 1; i < n; i++) {
        cin >> cities[i].lat >> cities[i].lon;
        cities[i].lon = (360 + cities[i].lon - cities[0].lon) % 360;
    }
    cities[0].lon = 0;
    cities[n] = cities[0];
    
    sort(cities + 1, cities + n, comp);
    
    for (k = 0; k <= t; k++) 
        for (i = 1; i <= n; i++) 
            for (m[i][k] = m[i][max(0, k-1)], j = 0; j < i; j++) {
                diff = abs(cities[i].lat - cities[j].lat);
                m[i][k] = max(m[i][k], (diff <= k) ? 1 + m[j][k-diff] : 0);
            }
    
    cout << m[n][t]-1;

    return 0;
}