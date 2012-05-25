
/*
    Olimpíada Brasileira de Informática
    Seletiva para a IOI, Teste III, 2008
    Problema: Viagem de volta ao mundo
    
    Data de submissão: 24/05/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: programacao-dinamica
    Complexidade: O(n²t)
    
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

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N = 501;

struct City {
    int lat, lon;
} cities[MAX_N];

int m[MAX_N][MAX_N], m_asc[MAX_N][MAX_N], m_desc[MAX_N][MAX_N];
int next[MAX_N];

bool comp(City a, City b) {
    if ( a.lon != b.lon )
        return a.lon < b.lon;
    else
        return a.lat < b.lat;
}

void compute_step(int x, int k, int mx[MAX_N][MAX_N]) {
    int i, j, diff;
    
    for (i = x; i < next[x]; i++) {
        mx[i][k] = m[i][max(0, k-1)];
        
        for (j = 0; j < x; j++) {
            diff = abs(cities[i].lat - cities[j].lat);
            mx[i][k] = max(mx[i][k], (diff <= k) ? 1 + m[j][k-diff] : 0);
        }
        
        for (j = x; j < i; j++) {
            diff = abs(cities[i].lat - cities[j].lat);
            mx[i][k] = max(mx[i][k], (diff <= k) ? 1 + mx[j][k-diff] : 0);
        }
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
            compute_step(i, k, m_asc); 
            reverse(cities + i, cities + next[i]);
            compute_step(i, k, m_desc);
            reverse(cities + i, cities + next[i]);
            
            for (j = 0; j < next[i]-i; j++) 
                m[i+j][k] = max(m_asc[i+j][k], m_desc[next[i]-j-1][k]);
        }
        
    }
   
    cout << m[n][t]-1 << endl;
    
    return 0;
}