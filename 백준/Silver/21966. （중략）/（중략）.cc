#include <iostream>

using namespace std;

int main() {
    int N;
    string s;
    bool isSame;
    
    cin >> N >> s;
    if (N <= 25) {
        cout << s;
    }
    else {
        isSame = true;
        for (int i = 11; i < N-11-1; i++) {
            isSame &= s[i] != '.';
        }
        
        if (isSame) {
            for (int i = 0; i < 11; i++)
                cout << s[i];
            cout << "...";
            for (int i = N-11; i < N; i++)
                cout << s[i];
        }
        else {
            for (int i = 0; i < 9; i++)
                cout << s[i];
            cout << "......";
            for (int i = N-10; i < N; i++)
                cout << s[i];
        }
    }
    return 0;
}