/*
    Olimpíada Brasileira de Informática
    Nível 2, Fase 1, 2012
    Problema: Tarzan
    
    Data de submissão: 31/03/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: grafos, busca-em-largura, grafos-conexos, geometria
    Complexidade: O(n²)
*/

#include <cstdio>
#include <queue>
using namespace std;

struct Point {
    int x, y;
};

// verifica se a distância entre duas árvores é menor que o tamanho do cipó
bool alcanca(int d, Point p1, Point p2) {
    // fazendo as comparações ao quadrado para evitar aritmética de
    // ponto-flutuante
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y) <= d*d;
}

int main() {
    Point points[1000];
    bool adj[1000][1000];
    bool alcancado[1000];
    int n, d, i, j, contaAlcancados = 1;
    queue<int> q;
    
    scanf("%d%d", &n, &d);
    
    for (i = 0; i < n; i++) {
        scanf("%d%d", &points[i].x, &points[i].y);
        alcancado[i] = false;
    }
    
    // computa todos os pares de árvores que são diretamente alcançáveis
    for (i = 0; i < n; i++)
        for (j = i; j < n; j++) 
            adj[i][j] = adj[j][i] = alcanca(d, points[i], points[j]);
    
    alcancado[0] = true;
    q.push(0);
    
    while ( !q.empty() ) {
        i = q.front();
        q.pop();
        
        for (j = 0; j < n; j++) 
            if ( !alcancado[j] && adj[i][j] ) {
                q.push(j);
                alcancado[j] = true;
                contaAlcancados++;
                
                if ( contaAlcancados == n ) {
                    printf("S");
                    return 0;
                }
            }
    }
    
    printf("N");
    return 0;
}
