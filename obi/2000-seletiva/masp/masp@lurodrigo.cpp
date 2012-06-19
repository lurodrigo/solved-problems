
/*
    Olimpíada Brasileira de Informática
    2000, Seletiva IOI
    Problema: MASP
    
    Data de submissão: 29/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: programacao-dinamica
    Complexidade: O(m*n)  
*/

#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

int p[100][100], mp[100][100], prev[100][100];

void compute_shortest_path(int n, int m) {
    int i, j, k;
    
    for (i = 0; i < n; i++) {
        mp[i][0] = p[i][0];
        prev[i][0] = -1;
    }
    
    for (j = 1; j < m; j++)
        for (i = 0; i < n; i++) {
            mp[i][j] = 1 << 28;
            
            for (k = -1; k <= 1; k++) {
                if ( k == -1 && n == 2 ) continue; 
            
                if ( mp[(n+i+k) % n][j-1] + p[i][j] < mp[i][j] ) {
                    mp[i][j] = mp[(n+i+k) % n][j-1] + p[i][j];
                    prev[i][j] = (n+i+k) % n;
                }     
            }
        }
}

void print_shortest_path(int n, int m) {
    int i, j, p = 0;
    for (i = 0; i < n; i++)
        if ( mp[i][m-1] < mp[p][m-1] )
            p = i;
            
    stack<int> pos;
    for (j = m-1; j >= 0; p = prev[p][j], j--)
        pos.push(p);
        
    for (j = 0; j < m; j++) {
        cout << pos.top() + 1 << " ";
        pos.pop();
    }
}

int main() {

    int i, j, m, n, teste = 1;
    
    while (true) {
        cin >> n >> m;
        
        if ( n == 0 && m == 0 )
            break;
            
        for (i = 0; i < n; i++) 
            for (j = 0; j < m; j++)
                cin >> p[i][j];

        cout << "Teste " << teste++ << endl;
        compute_shortest_path(n, m);
        print_shortest_path(n, m);
        cout << endl << endl;    
    }

    return 0;
}
