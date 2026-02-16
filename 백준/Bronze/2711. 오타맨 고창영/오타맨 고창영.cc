#include <iostream>

using namespace std;

int main() {
    int T, d;
    string s;
    
    cin >> T;
    while (T--) {
        cin >> d >> s;
        
        for (int i = 0; i < s.length(); i++) {
            if (i != d-1) {
                cout << s[i];
            }
        }
        cout << '\n';
    }

    return 0;
}