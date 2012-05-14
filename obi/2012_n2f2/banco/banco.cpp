
#include <iostream>
#include <queue>
using namespace std;

int main() {

    priority_queue<int, vector<int>, greater<int> > caixas;
    int count = 0, i, c, n, t, d, caixa;    

    cin >> c >> n;

    for (i = 0; i < c; i++)
        caixas.push(0);
    
    for (i = 0; i < n; i++) {
        cin >> t >> d;

        caixa = caixas.top();
        caixas.pop();

        // cout << caixa << " " << t << endl;

        if ( caixa > t + 20 ) {
            count++;
        }
    
        caixas.push(max(t, caixa) + d);
    }

    cout << count;
    
    return 0;
}
