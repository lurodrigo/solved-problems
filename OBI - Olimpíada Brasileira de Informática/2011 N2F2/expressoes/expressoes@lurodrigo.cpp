
/*
    Olimpíada Brasileira de Informática
    Nível 2, Fase 2, 2011
    Problema: Expressões
    
    Data de submissão: 29/03/2012
    Autor da solução: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: pilha, string
    Complexidade: O(sigma(|s|)) (a soma do tamanho de todas as strings)
*/

#include <cstdio>
#include <stack>
using namespace std;

int main() {
    int n;
    char str[100001];
    stack<char> s;
    bool result;
    
    scanf("%d", &n);
    
    while ( n-- ) {
        scanf("%s", str);
        
        result = true;
        for (int i = 0; str[i] != '\0'; i++) {
            if ( str[i] == '(' || str[i] == '[' || str[i] == '{' ) {
                s.push(str[i]);
            } else {
                
                if ( s.empty() ) {
                    result = false;
                    break;
                }
                
                char match = s.top();
                s.pop();
                
                if ((str[i] == ')' && match != '(') || 
                    (str[i] == ']' && match != '[') || 
                    (str[i] == '}' && match != '{') ) 
                {
                    result = false;
                    break;    
                } 
            }
        }
        
        if ( !s.empty() ) {
            result = false;
            while ( !s.empty() ) s.pop();
        }
        
        printf("%c\n", result ? 'S' : 'N');
    }

    return 0;
}
