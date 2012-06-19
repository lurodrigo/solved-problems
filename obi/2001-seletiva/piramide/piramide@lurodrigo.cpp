
/*
    Olimpíada Brasileira de Informática
    2001, Seletiva IOI
    Problema: Pirâmide
    
    Data de submissão: 09/05/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: programacao-dinamica
    Complexidade: O(n log n)
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Box {
    int width, depth;
    
    bool operator<(Box b) {
        return (width <= b.width && depth <= b.depth) ||
            (depth <= b.width & width <= b.depth);
    }   
} boxes[5000];

bool byArea(Box a, Box b) {
    return a.width*a.depth <= b.width*b.depth;
}

int m[5000];

int lis(int n) {
    int tallest = 0;
    
    for (int i = 0; i < n; i++) {
        m[i] = 1;
        
        for (int j = 0; j < i; j++)
            if ( 1+m[j] > m[i] && boxes[j] < boxes[i] )
                m[i] = 1 + m[j];
                
        if ( m[i] > m[tallest] )
            tallest = i;
    }
    
    return m[tallest];
}

int main() {
    int i, n, teste=1;
    
    while (true) {
        cin >> n;
        
        if (n == 0) break;
        
        for (i = 0; i < n; i++)
            cin >> boxes[i].width >> boxes[i].depth;
        
        sort(boxes, boxes + n, byArea);
                
        printf("Teste %d\n%d\n\n", teste++, lis(n));
    }

    return 0;
}
