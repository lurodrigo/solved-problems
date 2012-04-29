
/*
    Olimpíada Brasileira de Informática
    2003, Seletiva IOI
    Problema: Parque Jurássico
    
    Data de submissão: 29/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: programacao-dinamica
    Complexidade: O(m*n)  
*/

#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

int m[201][201];

void compute_scs(char s1[], int l1, char s2[], int l2) {
    int i, j;
    
    for (i = 0; i <= l1; i++)
        m[i][0] = i;
    for (j = 1; j <= l2; j++)
        m[0][j] = j;
        
    for (i = 1; i <= l1; i++)
        for (j = 1; j <= l2; j++)
            if ( s1[i] == s2[j] )
                m[i][j] = 1 + m[i-1][j-1];
            else
                m[i][j] = 1 + min(m[i-1][j], m[i][j-1]);     
}

void print_scs(char s1[], int l1, char s2[], int l2) {
    stack<char> scs;
    int i = l1, j = l2;
    
    while ( i != 0 || j != 0 ) {
        if ( s1[i] == s2[j] ) {
            scs.push(s1[i]);
            i--; j--;
        } else if ( i > 0 && m[i][j] == 1 + m[i-1][j] ) {
            scs.push(s1[i]);
            i--;
        } else {
            scs.push(s2[j]);
            j--;
        }
        
    }
        
    while ( !scs.empty() ) {
        cout << scs.top();
        scs.pop();    
    }
}

int main() {

    char s1[202], s2[202];
    int l1, l2, teste=1;

    while (true) {
        cin >> &s1[1];
        if ( strcmp(&s1[1], "#") == 0 )
            break;
        cin >> &s2[1];
        
        l1 = strlen(&s1[1]);
        l2 = strlen(&s2[1]);
        
        compute_scs(s1, l1, s2, l2);
        cout << "Teste " << teste++ << endl;
        print_scs(s1, l1, s2, l2);
        cout << endl << endl;
    }

    return 0;
}
