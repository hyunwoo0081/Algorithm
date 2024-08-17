#include <iostream>

using namespace std;

int main() {
    int N;
    string s;
    
    cin >> N >> s;
    for (int i = 1; i < N; i++) {
        if (s[i] == 'J')
            cout << s[i-1] << '\n';
    }

    return 0;
}