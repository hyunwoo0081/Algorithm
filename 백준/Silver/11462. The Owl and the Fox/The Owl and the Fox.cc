#include <iostream>
#define SIZE 100000

using namespace std;

int store[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, r, tmpN;
    string s;
    
    for (n = 1; n <= SIZE; n++) {
        r = 1;
        for (tmpN = n; !(tmpN % 10); tmpN /= 10, r *= 10);
        store[n] = n - r;
    }
    
    cin >> s;
    while (s != "END") {
        n = stoi(s);
        cout << store[n] << '\n';
        
        cin >> s;
    }

    return 0;
}