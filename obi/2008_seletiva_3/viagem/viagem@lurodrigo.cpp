
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
int m1[501], m2[501], next[501];

bool comp(City a, City b) {
    if ( a.lon != b.lon )
        return a.lon < b.lon;
    else
        return a.lat < b.lat;
}

void compute_step(int x, int k, int r[]) {
    int i, j, diff;
    
    for (i = x; i < next[x]; i++)
        for (r[i] = m[i][max(0, k-1)], j = 0; j < i; j++) {
            diff = abs(cities[i].lat - cities[j].lat);
            r[i] = max(m1[i], (diff <= k) ? 1 + m[j][k-diff] : 0);
        }
}

int main() {

    int i, j, k, x, n, t, diff;
    
    cin >> n >> t;
    
    cin >> cities[0].lat >> cities[0].lon;
    for (i = 1; i < n; i++) {
        cin >> cities[i].lat >> cities[i].lon;
        cities[i].lon = (360 + cities[i].lon - cities[0].lon) % 360;
    }
    cities[0].lon = 0;
    cities[n] = cities[0];
    
    sort(cities + 1, cities + n, comp);
    
    for (next[n] = n+1, i = n-1; i > 0; i--)
        next[i] = (cities[i].lon == cities[i+1].lon) ? next[i+1] : i + 1;
    
    for (k = 0; k <= t; k++) { 
        for (i = 1; i <= n; i = next[i]) {
        
            /*
                m(i, k) = máximo de cidades que se pode viajar com tarifa máxima k
                terminando na cidade i
                
                m(i, k) = max { 1 + m[j][k-cost(j, i)] | j < i }
                sendo cost(x, y) = |x.lat - y.lat|
                
                Isso funciona normalmente para cidades ordenadas pela longitude, sendo
                todas as longitudes distintas. Entretanto, as coisas ficam mais complicadas
                quando as longitudes não são todas distintas, pois podemos começar do sul
                e ir para o norte, do norte para o sul, ou ficar subindo e descendo.
                
                Na verdade, é fácil provar que só os dois primeiros casos são
                necessários de se considerar. Abaixo são computadas as melhores escolhas
                considerando ambos os casos, ficando somente com a melhor das duas.
            */
        
            compute_step(i, k, m1); 
            reverse(cities + i, cities + next[i]);
            compute_step(i, k, m2);
            reverse(cities + i, cities + next[i]);
            reverse(m2 + i, m2 + next[i]);
            
            for (j = i; j < next[i]; j++) {
                m[j][k] = max(m1[j], m2[j]);
                cout << m[j][k] << " ";
            }
        }
       
        cout << "\n";
    }
    
    
    
    cout << m[n][t]-1;

    return 0;
}