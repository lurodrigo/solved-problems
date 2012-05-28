
/*
    Olimpíada Brasileira de Informática
    2007, Nível 2, Fase 1
    Problema: Repositórios
    
    Data de submissão: 12/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: mapas
    Complexidade: O(c*log(c))
*/

#include <iostream>
#include <map>
using namespace std;

int main() {

    map<int, int> installed, available;
    
    int i, n_installed, n_available, p, v;
    
    cin >> n_installed >> n_available;
    
    for (i = 0; i < n_installed; i++) {
        cin >> p >> v;
        installed[p] = v;
    }
    
    for (i = 0; i < n_available; i++) {
        cin >> p >> v;
        available[p] = max(available[p], v);
    }
    
    for (map<int, int>::iterator it = available.begin(); it != available.end(); it++)
        if ( it->second > installed[it->first] )
            cout << it->first << " " << it->second << endl;

    return 0;
}
