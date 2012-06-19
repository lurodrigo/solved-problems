    
/*
    Olimpíada Brasileira de Informática
    2000, Seletiva IOI
    Problema: Árvores
    
    Data de submissão: 29/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: arvores
    Complexidade: O(n*h)  
*/

#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

struct Node {
     int id, left, right;
} nodes[10000];

int main() {

    int i, j, n, dir, count, teste = 1;
    queue<int> q;
    int id, pos;
    
    while (true) {
        cin >> n;
        
        if ( n == 0 )
            break;
        
        for (i = 0; i <= n; i++) {
            nodes[i].left = nodes[i].right = nodes[i].id = -1;
        }
        
        count = 0;
        for (i = 0; i < n; i++) {
            cin >> id;
            
            // lê as direções e as armazena numa pilha, para que
            // que possamos caminhar da raiz até o nó
            pos = 0;
            while ( true ) {
                cin >> dir;
                if ( dir == 0 ) break;
                
                if ( dir == -1 ) {               
                    if ( nodes[pos].left == -1 ) {
                        nodes[pos].left = ++count;
                        pos = count;
                    } else
                        pos = nodes[pos].left;
                } else {
                    if ( nodes[pos].right == -1 ) {
                        nodes[pos].right = ++count;
                        pos = count;
                    } else
                        pos = nodes[pos].right;
                }   
            }
          
            nodes[pos].id = id;
        }
        
        printf("Teste %d\n", teste++);
        
        q.push(0);
        while ( !q.empty() ) {
            id = q.front();
            q.pop();
            
            printf("%d ", nodes[id].id);
            if ( nodes[id].left != -1 )
                q.push(nodes[id].left);
            if ( nodes[id].right!= -1 )
                q.push(nodes[id].right);
        }
        
        printf("\n\n");
    }

    return 0;
}
