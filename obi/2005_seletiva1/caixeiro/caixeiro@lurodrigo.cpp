
/*
    Olimpíada Brasileira de Informática
    Seletiva para a IOI, Teste I, 2005
    Problema: O Problema do Caixeiro Viajante
    
    Data de submissão: 26/05/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: grafos, programacao-dinamica, lcs
    Complexidade: O(n³)
*/

#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
    bool found, isLeaf;
    int adj[300], path[300];
    int nadj, npath;
    
    // função auxiliar para que possa acessar o caminho como um vetor
    // 1-based qualquer
    int at(int i) {
        if ( i <= npath )
            return path[i-1];
        else
            return path[2*npath - i];
    }
} nodes[300];

int ft[601];

void prepare(int n) {
    for (int i = 0; i < n; i++) {
        nodes[i].found = nodes[i].isLeaf = false;
        nodes[i].nadj = nodes[i].npath = 0;
    }
    
    nodes[0].found = true;
    nodes[0].path[0] = 0;
    nodes[0].npath = 1;
}

void bfs(int n) {
    queue<int> q;
    int i, u, v, nchildren;
    
    q.push(0);
    
    while ( !q.empty() ) {
        u = q.front();
        q.pop();
        
        for (nchildren = i = 0, v = nodes[u].adj[i]; i < nodes[u].nadj; i++, v = nodes[u].adj[i])
            if ( !nodes[v].found ) {
                nodes[v].found = true;    
                q.push(v);
                // o caminho até v é o caminho até u
                copy(nodes[u].path, nodes[u].path + nodes[u].npath, nodes[v].path);
                // acrescentando o nó v
                nodes[v].path[nodes[u].npath] = v;
                nodes[v].npath = nodes[u].npath + 1;
                nchildren++;
            }
            
        if ( nchildren == 0 )
            nodes[u].isLeaf = true;
    }
}

int row_prev[600], row_cur[600];
// calcula o tamanho da maior subsequência comum entre os festivais e o caminho
// até uma determinada cidade (ida e volta)
int lcs(int f, int u) {
    int i, j, len = 2*nodes[u].npath;
    
    fill(row_cur, row_cur + len + 1, 0);

    for (i = 1; i <= f; i++) {
        copy(row_cur, row_cur + len + 1, row_prev);
        
        for (j = 1; j <= len; j++)
            if ( ft[i] == nodes[u].at(j) )
                row_cur[j] = 1 + row_prev[j-1];
            else
                row_cur[j] = max(row_cur[j-1], row_prev[j]);
    }
                
    return row_cur[len];
}

int main() {
    int i, j, u, v, n, f, maior, teste = 1;
    
    while (true) {
        
        cin >> n >> f;
        
        if (n == 0) break;
 
        prepare(n);
        for (i = 0; i < n - 1; i++) {
            cin >> u >> v;
            u--; v--;
            nodes[u].adj[nodes[u].nadj++] = v;
            nodes[v].adj[nodes[v].nadj++] = u;
        }
        bfs(n);
        
        for (i = 1; i <= f; i++) {
            cin >> ft[i];
            ft[i]--;
        }
       
        // o valor a ser computado é a maior LCS entre os festivais e o
        // caminho até os nós folhas (os outros nós não precisam ser analisados
        // porque seus caminhos estão contidos nos caminhos de seus filhos)
        for (maior = i = 0; i < n; i++)
            if ( nodes[i].isLeaf )
                maior = max(maior, lcs(f, i));

        printf("Teste %d\n%d\n\n", teste++, maior);
    }

    return 0;
}
