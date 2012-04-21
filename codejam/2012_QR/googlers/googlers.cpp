
/*
    Google Code Jam
    2012 Qualification Round
    Problem: Dancing with the Googlers
    
    Submission date: 21/04/2012
    Solved by: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: arithmetic
    Complexity: O(n)
*/

#include <iostream>
#include <cstdio>
using namespace std;

int pGreater(int t, int p) {
    /* 
        return codes:
        0: no score greater than p
        1: has score greater than p without surprising
        2: has score greater than p only surprising
    */
    int mod = t % 3;
    int div = t / 3;
    
    if ( mod == 1 )
        return ( div + 1 >= p) ? 1 : 0;
    else if ( mod == 2 ) {
        if ( div + 1 >= p ) return 1;
        if ( div + 2 >= p ) return 2;
        return 0;
    } else {
        if ( div >= p ) return 1;
        if ( t >= 3 && div + 1 >= p ) return 2;
        return 0;
    }
}

int main() {

    int i, j, t, n, s, p, ti, result, count;
    
    cin >> t;
    
    for (i = 1; i <= t; i++) {
        cin >> n >> s >> p;
        
        count = 0;
        for (j = 0; j < n; j++) {
            cin >> ti;
            result = pGreater(ti, p);
            
            if ( result == 2 && s > 0 ) {
                count++;
                s--;
            } else if ( result == 1 ) {
                count++;
            }
        }
        
        printf("Case #%d: %d\n", i, count);
    }

    return 0;
}
