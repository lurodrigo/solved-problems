
/*
    Olimpíada Brasileira de Informática
    Nível 2, Fase 2, 2012
    Problema: Álbum de fotos
    
    Data de submissão: 12/05/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: ad-hoc, comparações
    Complexidade: O(1)
*/

#include <iostream>
#include <cstdio>
using namespace std;

struct Box {
    int width, height;

    Box(int w = 0, int h = 0) {
        width = w;
        height = h;
    }

    Box flip() {
        return Box(height, width);
    }
};

bool fits(Box a, Box b, Box c) {
    // não gira nenhuma
    return (a.width + b.width <= c.width && max(a.height, b.height) <= c.height) ||
    // gira a segunda
        (a.width + b.height <= c.width && max(a.height, b.width) <= c.height) ||
    // gira a primeira
        (a.height + b.width <= c.width && max(a.width, b.height) <= c.height) ||
    // gira as duas
        (a.height + b.height <= c.width && max(a.width, b.width) <= c.height);
}

int main() {

	int x, y;
	Box c, a, b;

	cin >> x >> y;
	c = Box(x, y);
    cin >> x >> y;
	a = Box(x, y);
    cin >> x >> y;
	b = Box(x, y);

    if ( fits(a, b, c) || fits(a, b, c.flip()) )
	    cout << "S";
	else
	    cout << "N";
	    

	return 0;
}
