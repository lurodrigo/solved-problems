
/*
    Olimpíada Brasileira de Informática
    Nível 1, Fase 2, 2011
    Problema: Colorindo
    
    Data de submissão: 12/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: grafos, flood-fill, busca-em-largura
    Complexidade: O(n*m)
*/

#include <iostream>
#include <cstdio>
#include <list>
#include <queue>
using namespace std;

enum State { EMPTY, FILLED, PAINTED };

struct Point { 
    int x, y;
    
    Point(int x=0, int y=0) {
        this->x = x;
        this->y = y;
    }    
};

State image[200][200];

bool inImage(int n, int m, Point p) {
    return p.x >= 0 && p.x < n && p.y >= 0 && p.y < m && 
        (image[p.x][p.y] == EMPTY);
}

int fill(int n, int m, Point start) {
    queue<Point> q;
    int count = 1;
    
    q.push(start);
    
    while ( !q.empty() ) {
        Point p = q.front();
        q.pop();

        for (int i = -1; i <= 1; i++)
            for (int j = -1; j <= 1; j++)
                if ( inImage(n, m, Point(p.x + i, p.y + j)) ) {
                    q.push(Point(p.x + i, p.y + j)); 
                    image[p.x + i][p.y + j] = PAINTED;
                    count++;
                }
    }
    
    return count;
}

int main() {
    int i, j, n, m, k;
    Point start, filled;
    
    cin >> n >> m >> start.x >> start.y >> k;
    
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            image[i][j] = EMPTY;
    image[--start.x][--start.y] = PAINTED;
    
    for (i = 0; i < k; i++) {
        cin >> filled.x >> filled.y;
        image[filled.x-1][filled.y-1] = FILLED;
    }   
 
    cout << fill(n, m, start);
    
    return 0;
}
