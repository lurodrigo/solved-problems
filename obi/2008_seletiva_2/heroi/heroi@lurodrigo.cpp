
/*
    Olimpíada Brasileira de Informática
    Seletiva para a IOI, Teste II, 2008
    Problema: Super-herois
    
    Data de submissão: 17/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: conjuntos, mapas
    Complexidade: O(n² log n) (?)
*/

#include <iostream>
#include <list>
#include <set>
#include <map>
#include <string>
using namespace std;
using std::string;

struct Pessoa {
    bool podeSer[100];
    string nome;
    bool eSuperHeroi;
} people[200];

map<string, int> nomeToId;

int main() {

    int i, j, n, m, c, id;
    string nome;
    list<int> super, normal;
    
    cin >> n >> m;
    
    for (i = 0; i < 2*n; i++) {
        cin >> people[i].nome;
        nomeToId[people[i].nome] = i;
        people[i].eSuperHeroi = i < n;
        
        for (j = 0; i >= n && j < n; j++) 
            people[j].podeSer.insert(i);
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
    }
    
    return 0;
}