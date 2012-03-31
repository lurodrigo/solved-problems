
/*
    Olimpíada Brasileira de Informática
    Nível 2, Fase 2, 2008
    Problema: Chuva
    
    Data de submissão: 29/03/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: union-find, conjuntos-disjuntos
    Complexidade: O(m)
*/

#include <iostream>
using namespace std;

struct Node {
    int parent, rank;
};

void makeSet(Node nodes[], int len) {
    for (int i = 0; i < len; i++) {
        nodes[i].parent = i;
        nodes[i].rank = 0;
    }
}

int find(Node nodes[], int x) {
    if ( x != nodes[x].parent ) 
        nodes[x].parent = find(nodes, nodes[x].parent);
    return nodes[x].parent;
}

void link(Node nodes[], int x, int y) {
    if ( nodes[x].rank > nodes[y].rank ) {
        nodes[y].parent = x;
    } else {
        nodes[x].parent = y;
        
        if ( nodes[x].rank == nodes[y].rank ) {
            nodes[y].rank = nodes[y].rank + 1;
        }
    }
}

void unify(Node nodes[], int x, int y) {
    link(nodes, find(nodes, x), find(nodes, y));
}

int main() {
    
    int nbancos, noperacoes, x, y;
    char operacao;
    Node nodes[100000];
    
    cin >> nbancos >> noperacoes;
    makeSet(nodes, nbancos);
    
    for (int i = 0; i < noperacoes; i++) {
        cin >> operacao >> x >> y;
        x--; y--;
        
        if ( operacao == 'C' ) {
            cout << ((find(nodes, x) == find(nodes, y)) ? "S" : "N") << endl;
        } else {
            unify(nodes, x, y);
        }
    }
    
    return 0;
}
