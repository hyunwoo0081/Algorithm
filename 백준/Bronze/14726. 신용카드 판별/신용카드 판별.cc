#include <iostream>
#define SIZE 16

using namespace std;

int main() {
    int T, n, result;
    string s;
    
    cin >> T;
    while (T--) {
        cin >> s;
        
        result = 0;
        for (int i = 0; i < SIZE; i++) {
            n = s[i] - '0';
            
            n = i%2 ? n : n*2;
            
            if (n >= 10) {
                n = n/10 + n%10;
            }
            
            result += n;
        }
        
        if (result % 10 == 0)
            cout << "T\n";
        else
            cout << "F\n";
    }

    return 0;
}