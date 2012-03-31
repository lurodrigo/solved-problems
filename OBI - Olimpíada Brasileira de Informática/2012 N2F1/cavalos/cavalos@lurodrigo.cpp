
/*
    Olimpíada Brasileira de Informática
    Nível 2, Fase 1, 2012
    Problema: Tabuleiro esburacado
    
    Data de submissão: 31/03/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: ad-hoc, tabuleiro, simulação
    Complexidade: O(n)
*/

#include <iostream>
using namespace std;

// matriz contendo quanto altera cada o x e o y em cada movimento
const int movimentos[8][2] = {
    {1, 2},
    {2, 1},
    {2, -1},
    {1, -2},
    {-1, -2},
    {-2, -1},
    {-2, 1},
    {-1, 2}
};

// posições predefinidas dos buracos
const int buracos[4][2] = {

};

void move(int &x, int &y, int m) {
    x += movimentos[x-1][0];
    y += movimentos[y-1][1];
}

void eBuraco(int x, int y) {
    for (int i = 0; i < 4; i++)
        if ( x == buracos[i][0] && y == buracos[i][1] )
            return true;
            
    return false;
}

int main() {
    int i, n, m, x = 4, y = 3, conta = 0;
    bool caiu = false;

    cin >> n;
    
    for (i = 0; i < n; i++) {
        cin >> m;
        
        if ( !caiu ) {
            move(x, y, m);
            conta++;
            
            if ( eBuraco(x, y) ) 
                caiu = true;
        }
    }
    
    cout << conta;

    return 0;
}
