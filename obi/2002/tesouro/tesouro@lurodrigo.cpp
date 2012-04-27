
/*
    Olimpíada Brasileira de Informática
    2002
    Problema: Caça ao tesouro
    
    Data de submissão: 12/04/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: programacao-dinamica, subset-sum
    Complexidade: O(nt) (por caso de teste)

    Esse problema é mais simples do que parece. Na verdade, é só perceber
    que ele pode ser reduzido ao problema de, dado um conjunto S, encontrar
    um subconjunto de S que some T.
    
    São dados valores X e Y iniciais e N objetos. Some X e Y e os valores
    de cada objeto, esse é o tesouro total, chamemos de T. João e José, 
    cada um, devem ficar com um subtotal de T/2. 
    
    De cara, já podemos detectar alguns casos negativos:
    1) Se T for ímpar, é impossível efetuar a divisão
    2) Se min(X, Y) + T < max(X, Y), é impossível efetuar a divisão
        (pois mesmo que todos os itens da arca fiquem com o que tem o menor
         valor inicial, ainda não alcançará aquele com o maior valor inicial)
         
    Chamemos de Tx o valor total dos itens da arca que devem ficar com João,
    e Ty o valor total tos itens que devem ficar com José. Como a soma
    deve ser T/2 pra cada um, temos que X + Tx = T/2 => Tx = T/2-X
    
    Ou seja, só nos resta verificar se existe um subconjunto dos itens da
    arca cuja soma dos valores seja T/2-X.

*/

#include <iostream>
using namespace std;

/*
Seja V um vetor de valores indexados de 1 a N (por conveniência).

S(t, n) é uma função booleana que retorna True caso seja possível somar até t
usando apenas os valores v[1], v[2] ... v[n].

Os casos base da nossa recorrência são:
    S(0, k) é True para qualquer k em [0 .. n] (pois não é necessário nenhum item
        para obter uma soma de 0)
    S(t, 0) é False para qualquer t >= 1, pois não é possível obter a soma
        sem usar nenhum elemento dos conjunto V.
        
A partir desses valores, é possível calcular os subsequentes usando a seguinte 
recorrẽncia:
    
    S(i, j) = True, se S(i, j-1) 
        (pois já é possível somar i sem mesmo usar o item v[k]) 
    S(i, j) = True, se i >= v[j] e S(i-v[j], j-1)
        (pois é possível somar i-v[j] usando alguns dos itens de v[1] a v[j], 
            logo, basta usar o item v[j] para obter a soma i)
    S(i, j) = False, caso nenhuma das condições acima se aplique
*/

bool sums[10001][101];
bool subset_sum(int v[], int n, int t) {
    int i, j;
    
    // Inicializa os casos-base
    for (j = 0; j <= n; j++)
        sums[0][j] = true;
    for (i = 1; i <= t; i++)
        sums[i][0] = false;
   
   // Calcula todos os outros valores, baseado na recorrência explicada.
    for (j = 1; j <= n; j++)
        for (i = 1; i <= t; i++) {
            sums[i][j] = sums[i][j-1];
            if ( i >= v[j] && sums[i-v[j]][j-1] )
                sums[i][j] = true;
        }

    return sums[t][n];
}

/*
    Tem o mesmo raciocínio, porém aplica algumas otimizações para poupar tempo
    e memória.

    Otimização 1: 
        Não é preciso de uma matriz para guardar todos os valores.
        Note que S(i, j) é a mesma coisa que S(i, j-1), exceto se 
            S(i, j-1) for false e (i-v[j], j-1) for true. Nesse caso, altera-se
            S(i, j) para true.
        Basicamente, usa-se só um vetor para guardar os valores que podem ser
        somados, e altera-se para true os resultados do item anterior somente
        se necessário.
        
        Note que isso poderia levar a considerar mais de uma vez o mesmo item.
        Por exemplo, se v = {7}. Inicialmente, só é possível conseguir
        somar 0. Quando chegasse em s[7], 7-v[1] seria 0, que é true, logo,
        s[7] seria true. Porém, quando cheguasse em s[14], já consideraria
        s[14-s[1]] = s[7] como true, usando duas vezes o elemento 7 (o que é 
        incorreto). 
        
        Isso pode ser resolvido facilmente percorrrendo os valores em ordem
        decrescente.
        
      
    Otimização 2:
        Não é preciso percorrer todos os valores no intervalo [1 .. t]
        
        Note que, ao analisar o item j, os valores de s[1..v[j]-1] serão mantidos, 
        pois nesses casos, i < v[j] e, consequentemente, i-v[j] é negativo e não
        deve ser considerado. Logo, só considere os items de v[j] em diante.
        
        Note também que na iteração j, o maior valor de s que pode ser true
        é v[1] + v[2] + .. v[j], pois, obviamente, esse é o maior valor 
        que pode ser obtido somando elementos de v[1 .. j].
        
        Então, na iteração j, só precisamos considerar as posições no intervalo
        s[v[j].. sum(v[1..j])]
         
*/

bool osums[10001];
bool optimized_subset_sum(int v[], int n, int t) { 
    int i, j, max_til_now = 0;
    
    // Casos base 
    for (i = 1; i <= t; i++)
        osums[i] = false;
    osums[0] = true;
    
    for (j = 1; j <= n; j++) {
        max_til_now += v[j];
        for (i = min(max_til_now, t); i >= v[j]; i--)
            osums[i] = osums[i] || osums[i-v[j]];
    }

    return osums[t];
}

int main() {

    int n, i, x, y, sum, t = 1, v[101];

    while (true) {
        cin >> x >> y >> n;
        
        if ( x == 0 && y == 0 && n == 0 )
            break;
            
        for (sum = 0, i = 1; i <= n; i++) {
            cin >> v[i];
            sum += v[i];
        }
            
        cout << "Teste " << t++ << endl;
        if ( (x + y + sum) % 2 || min(x, y) + sum < max(x, y) ) {
            cout << "N\n\n";
            continue;
        }
        
        cout << (optimized_subset_sum(v, n, (x+y+sum)/2 - x) ? "S\n\n" : "N\n\n");
    }
    
    return 0;
}
