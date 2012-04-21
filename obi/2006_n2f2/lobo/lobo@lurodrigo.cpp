
/*
    Olimpíada Brasileira de Informática
    Nível 2, Fase 2, 2006
    Problema: Lobo mau
    
    Data de submissão: 21/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: flood-fill
    Complexidade: O(r*c)
*/

#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

bool traversed[250][250];
char matrix[250][251];
int rows, cols;

struct Coord {
    int r, c;
    
    Coord(int _r = 0, int _c = 0) {
        this->r = _r;
        this->c = _c;
    }
};

void eval(Coord c, int &s, int &w) {
    if ( matrix[c.r][c.c] == 'v')
        w++;
    else if ( matrix[c.r][c.c] == 'k' )
        s++;
}

bool valid(Coord co) {
    if ( (co.r >= 0) && co.r < rows && co.c >= 0 && co.c < cols &&
    matrix[co.r][co.c] != '#' && !traversed[co.r][co.c] ) {
        traversed[co.r][co.c] = true;
        return true;
    } 
    
    return false;
}

const int d[4][2] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};

int whoWins(Coord src, int &sheeps, int &wolves) {
    int s = 0, w = 0;
    queue<Coord> q;
    
    q.push(src);
    
    while ( !q.empty() ) {
        Coord c = q.front();
        q.pop();
        eval(c, s, w);
        
        for (int i = 0; i < 4; i++) {
            Coord n = Coord(c.r+d[i][0], c.c+d[i][1]);
            
            if ( valid(n) )
                q.push(n);
        }
    }
   
    if ( s > w ) 
        sheeps += s;
    else
        wolves += w;       
}

int main() {

    int i, j, r, c, sheeps, wolves;
    
    cin >> rows >> cols;
    
    for (i = 0; i < rows; i++) {
        scanf("%s", matrix[i]);
    }
    
    sheeps = wolves = 0;
    
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            if ( valid(Coord(i, j)) )
                whoWins(Coord(i, j), sheeps, wolves);
                    
    cout << sheeps << " " << wolves;
    
    return 0;
}
