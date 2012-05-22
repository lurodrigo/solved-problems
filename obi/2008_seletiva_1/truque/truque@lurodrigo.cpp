
/*
    Olimpíada Brasileira de Informática
    Seletiva para a IOI, Teste I, 2008
    Problema: O Truque
    
    Data de submissão: 17/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: ad-hoc
    Complexidade: O(n³) (?)
    
    (Provavelmente existe uma solução O(n²) ou O(n log n), mas não precisamos
    nos preocupar com eficiência considerando o tamanho da entrada)
*/

#include <iostream>
#include <string>
using namespace std;
using std::string;

int order[300];
bool deleted[300];

int main() {
    string nomes[300];
    
    int n, i, c, pos = -1;
    
    cin >> n;
    
    for (i = 0; i < n; i++)
        cin >> nomes[i];
        
    for (i = 0; i < n; i++) {     
        for (c = 0; c < nomes[i].length(); c++)
            while ( deleted[pos = (pos + 1) % n] );
        
        order[pos] = i;
        deleted[pos] = true;
    }
    
    for (i = 0; i < n; i++)
        cout << nomes[order[i]] << endl;

    return 0;
}