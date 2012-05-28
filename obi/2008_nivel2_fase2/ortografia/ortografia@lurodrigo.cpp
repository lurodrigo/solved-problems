/*
    Olimpíada Brasileira de Informática
    2008, Nível 2, Fase 2
    Problema: Ortografia
    
    Data de submissão: 29/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: programacao-dinamica, distancia-de-edicao
    Complexidade: O(m*n)  
*/

#include <iostream>
#include <cstring>
using namespace std;

int ed[21][21];

bool editDistance(char s[], int ls, char t[], int lt) {
    int i, j;
    
    for (i = 0; i <= ls; i++)
        ed[i][0] = i;
    for (j = 0; j <= lt; j++)
        ed[0][j] = j;
        
    for (i = 1; i <= ls; i++)
        for (j = 1; j <= lt; j++)
            ed[i][j] = min(
                min(1 + ed[i-1][j], // remoção 
                    1 + ed[i][j-1]), // inserção
                ed[i-1][j-1] + ((s[i] == t[j]) ? 0 : 1)); // manutenção ou troca
                
     return ed[ls][lt] <= 2;
}

int main() {

    int i, j, n, m;
    char dict[1000][22], word[100][22]; 
    
    cin >> n >> m;
    for (i = 0; i < n; i++)
        cin >> &dict[i][1];
    for (i = 0; i < m; i++)
        cin >> &word[i][1];
        
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++)
            if ( editDistance(word[i], strlen(&word[i][1]), dict[j],
            strlen(&dict[j][1])) )
                cout << &dict[j][1] << " ";
        cout << endl;
    }

    return 0;
}
