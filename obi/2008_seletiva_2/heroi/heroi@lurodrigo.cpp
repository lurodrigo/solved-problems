
/*
    Olimpíada Brasileira de Informática
    Seletiva para a IOI, Teste II, 2008
    Problema: Super-herois
    
    Data de submissão: 17/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: estruturas-de-dados
    Complexidade: O(e*max(m)²) (?)
*/

#include <iostream>
#include <list>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
using std::string;

string nomes[200];

int countPodeSer[100];
bool impossivel;
bool podeSer[100][100];

void naoPodeSer(int i, int j, int n) {
    if ( podeSer[i][j-n] )
        countPodeSer[i]--;
    podeSer[i][j-n] = false;   
    
    if ( countPodeSer[i] == 0 )
        impossivel = true;
}

map<string, int> nomeToId;

int main() {

    int i, j, n, m, c, id;
    string nome;
    list<int> super, normal;
    list<int>::iterator it, jt;
    
    cin >> n >> m;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            podeSer[i][j] = true;
        countPodeSer[i] = n;
    }
    
    for (i = 0; i < 2*n; i++) {
        cin >> nomes[i];
        nomeToId[nomes[i]] = i;
    }
    
    for (i = 0; i < m; i++) {
        cin >> c;
        
        super.clear();
        normal.clear();
        
        for (j = 0; j < c; j++) {
            cin >> nome;
            id = nomeToId[nome];
            
            if ( id < n )
                super.push_back(id);
            else
                normal.push_back(id);
        }
        
        for (it = super.begin(); it != super.end(); it++)
            for (jt = normal.begin(); jt != normal.end(); jt++)
                naoPodeSer(*it, *jt, n);
    }
    
    if ( impossivel ) {
        cout << "IMPOSSIVEL\n";
    } else
        for (i = 0; i < n; i++) {
            cout << nomes[i] << ": ";
            
            for (j = 0; j < n; j++)
                if ( podeSer[i][j] )
                    cout << nomes[j+n] << " ";
                    
            cout << endl;
        }
    
    return 0;
}
