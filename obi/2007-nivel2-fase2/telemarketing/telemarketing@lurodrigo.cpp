
/*
    Olimpíada Brasileira de Informática
    2007, Nível 2, Fase 2
    Problema: Telemarketing
    
    Data de submissão: 12/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: fila-de-prioridade
    Complexidade: O(l*log(v))
*/

#include <iostream>
#include <queue>
using namespace std;

struct Vendedor {
    int tempo, id;
    
    Vendedor(int _id=0) {
        tempo = 0;
        id = _id;
    }
};

bool operator<(const Vendedor a, const Vendedor b) {
    if ( a.tempo != b.tempo )
        return a.tempo >= b.tempo;
    else
        return a.id >= b.id;
}

int conta[1000];

int main() {   
    priority_queue<Vendedor> vendedores;
    int i, d, v, l;
    
    cin >> v >> l;
   
    for (i = 0; i < v; i++)
        vendedores.push(Vendedor(i));
    
    for (i = 0; i < l; i++) {
        Vendedor top = vendedores.top();
        vendedores.pop();
        cin >> d;
        top.tempo += d;
        conta[top.id]++;
        vendedores.push(top);
    }
    
    for (i = 0; i < v; i++) 
        cout << i+1 << " " << conta[i] << endl;

    return 0;
}
