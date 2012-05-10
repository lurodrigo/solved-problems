
/*
    Olimpíada Brasileira de Informática
    2007, Seletiva IOI Final
    Problema: Viagem Aérea
    
    Data de submissão: 10/05/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: grafos, dijkstra
    Complexidade: O(n**2)
*/

#include <iostream>
#include <cstdio>
using namespace std;

const int MAX_N = 1000;
const int UNDEF = 1 << 28;

struct Cost {
    int price, duration, flights;
    
    Cost(int a = UNDEF, int b = UNDEF, int c = 1) {
        price = a;
        duration = b;
        flights = c;
    }
    
    Cost operator+(Cost e) {
        return Cost(price + e.price, duration+e.duration, flights+e.flights);
    }
};

struct Node {
    Cost cost;
    Cost edges[MAX_N];
    bool visited;
} nodes[MAX_N];

bool comp_r(Cost a, Cost b) {
    if ( a.price != b.price )
        return a.price < b.price;
    else if ( a.duration != a.duration )
        return a.duration < b.duration;
    else
        return a.flights < b.flights;
}

bool comp_e(Cost a, Cost b) {
    if ( a.duration != a.duration )
        return a.duration < b.duration;
    else if ( a.price != b.price )
        return a.price < b.price;
    else
        return a.flights < b.flights;
}

bool (*comp)(Cost, Cost);

int extract_min(int n) {
    int min, i;
    
    for (min = 0; nodes[min].visited; min++);
    for (i = min+1; i < n; i++)
        if ( !nodes[i].visited && comp(nodes[i].cost, nodes[min].cost) )
            min = i;
            
    nodes[min].visited = true;
    return min;
}

void relax(int u, int v) {
    nodes[v].cost = min(nodes[v].cost, 
        nodes[u].cost + nodes[u].edges[v], comp);
}

int main() {
    int i, n, m, s, f, u, v, c, d;
    char t;
    
    cin >> n >> m >> t;
    cin >> s >> f;
    
    s--; f--;
    if ( t == 'P' )
        comp = &comp_r;
    else
        comp = &comp_e;
    
    for (i = 0; i < m; i++) {
        cin >> u >> v >> c >> d;    
        u--; v--;
        nodes[u].edges[v] = min(nodes[u].edges[v], Cost(c, d), comp);
    }
    
    nodes[s].cost = Cost(0, 0);
    for (i = 2; i <= n; i++) {
        u = extract_min(n);
        
        for (v = 0; v < n; v++)
            relax(u, v);
    }
    
    if ( nodes[f].cost.price == UNDEF )
        printf("-1\n");
    else
        printf("%d %d %d\n", nodes[f].cost.price, nodes[f].cost.duration,
            nodes[f].cost.flights-2);
    
    return 0;
}
