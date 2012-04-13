
/*
    Olimpíada Brasileira de Informática
    2004
    Problema: Orkut
    
    Data de submissão: 12/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: grafos, ordenacao-topologica, busca-em-profundidade, mapas
    Complexidade: O((v + e)*log(v))
    Versão 1: Usando busca em largura recursiva e mapa.
*/

#include <iostream>
#include <cstdio>
#include <map>
#include <list>
#include <string>
#include <stack>
using namespace std;
using std::string;

enum Color {WHITE, GRAY, BLACK};

struct Node {
    Color color;
    int id;
    string name;
    list<int> edges;
};

bool dfs_visit(Node nodes[], int n, list<int> &order, int u) {
    list<int>::iterator it;
    stack<int> st;
    
    st.push(u);
    nodes[u].color = GRAY;
    while ( !st.empty() ) {
        u = st.top();
        
        if ( nodes[u].edges.empty() ) {
            nodes[u].color = BLACK;
            order.push_front(u);  
            st.pop();
        } else {
            it = nodes[u].edges.begin();
            int v = *it;
            nodes[u].edges.pop_front();
            
            if ( nodes[v].color == GRAY ) {
                order.clear();
                return false;
            } else if ( nodes[v].color == WHITE ) {
                nodes[v].color = GRAY;
                st.push(v);
            }  
        }       
    }
    
    return true;
}

void dfs(Node nodes[], int n, list<int> &order) {
    for (int i = 0; i < n; i++)
        nodes[i].color = WHITE;
    for (int i = 0; i < n; i++)
        if ( nodes[i].color == WHITE )
            if ( !dfs_visit(nodes, n, order, i) ) 
                return;
}

int main() {
    Node nodes[100];
    // mapeia os nomes para os índices dos nós
    map<string, int> index;
    list<int> order;
    string name;
    int i, j, n, m, u, v, teste=0;
    
    while (true) {
        cin >> n;
        
        if (n == 0) 
            break;
        
        printf("Teste %d\n", ++teste);
        
        index.clear();
        for (i = 0; i < n; i++) {
            cin >> nodes[i].name;
            nodes[i].id = i;
            nodes[i].edges.clear();
            index[nodes[i].name] = i;
        }
        
        for (i = 0; i < n; i++) {
            cin >> name >> m;
            u = index[name];
            
            for (j = 0; j < m; j++) {
                cin >> name;
                v = index[name];
                nodes[v].edges.push_back(u);
            }
        }
        
        order.clear();
        dfs(nodes, n, order);
        
        if ( order.empty() ) {
            printf("impossivel\n\n");
        } else {
            for (list<int>::iterator it = order.begin(); it != order.end(); it++) {
                cout << nodes[*it].name << " ";
            }
            printf("\n\n");
        }
            
    }
    
    return 0;
}
