
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int i, n, k, a[10000];

    cin >> n;

    for (i = 0; i < n; i++)
        cin >> a[i];

    cin >> k;

    for (i = 0; i < n && a[i] <= k/2; i++)
        if ( binary_search(a+i+1, a+n, k-a[i]) ) {
            cout << a[i] << " " << k-a[i];
            break;
        }

    return 0;
}
