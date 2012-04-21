/*
    Google Code Jam
    2012 Qualification Round
    Problem: Recycled numbers
    
    Submission date: 21/04/2012
    Solved by: Luiz Rodrigo <@lurodrigo> <luizrodri.go@hotmail.com>
    Tags: arithmetic
    Complexity: O(n*log(n))
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

int digits(int n) {
    int i;
    for (i = 0; n > 0; i++)
        n /= 10;
    return i;
}

int count_movs(int n, int max) {
    int power[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};
    int perm = n, d = digits(n);
    set<int> perms;
    
    for (int i = 0; i < d; i++) {
        perm = perm/10 + (perm%10) * power[d-1];
        if ( perm <= max && perm > n ) perms.insert(perm);
    }
    
    return perms.size();
}

int main() {
    int n, i, j, min, max, count;
   
    cin >> n;
    
    for (i = 1; i <= n; i++) {
        cin >> min >> max;
        
        for (count = 0, j = min; j <= max; j++) {
            count += count_movs(j, max);
        }
        
        printf("Case #%d: %d\n", i, count);
    }

    return 0;
}
