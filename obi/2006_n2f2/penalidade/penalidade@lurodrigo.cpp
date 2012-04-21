
/*
    Olimpíada Brasileira de Informática
    Nível 2, Fase 2, 2006
    Problema: Penalidade Mínima
    
    Data de submissão: 21/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: programacao-dinamica
    Complexidade: O(n²)
*/

#include <iostream>
using namespace std;

struct Div {
    int d2, d5;
    
    Div() {}
    
    Div(int n) {
       
        if (n == 0) {
            d2 = d5 = 1 << 28;
            return;
        }
        
        d2 = d5 = 0;
        
        if (n == 1) return;
        
        while (n > 1 && n%2 == 0) {
            n /= 2;
            d2++;
        }
        
        while (n > 1 && n%5 == 0) {
            n /= 5;
            d5++;
        }
    }
    
    Div operator+(Div d) {
        Div n(0);
        n.d2 = d2 + d.d2;
        n.d5 = d5 + d.d5;
        return n;
    }
    
    bool operator<(Div d) {
        if ( min(d2, d5) != min(d.d2, d.d5) ) 
            return min(d2, d5) < min(d.d2, d.d5);
        else    
            return max(d2, d5) < max(d.d2, d.d5);
    }
};

int main() {

    Div m[1000][1000], c;
    
    int n, x, i, j;
    
    cin >> n;
    
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            cin >> x;
            m[i][j] = Div(x);
        }
          
    for (i = 1; i < n; i++) {
        m[0][i] = m[0][i] + m[0][i-1];
        m[i][0] = m[i][0] + m[i-1][0];
    }  
    
    for (i = 1; i < n; i++)
        for (j = 1; j < n; j++)
            if ( m[i][j] + m[i-1][j] < m[i][j] + m[i][j-1] )
                m[i][j] = m[i][j] + m[i-1][j];
            else
                m[i][j] = m[i][j] + m[i][j-1];

    cout << min(m[n-1][n-1].d2, m[n-1][n-1].d5);

    return 0;
}
