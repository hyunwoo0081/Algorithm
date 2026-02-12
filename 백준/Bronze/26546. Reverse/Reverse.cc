#include <iostream>

using namespace std;

int main() {
    int t, start, end;
    string s;
    
    cin >> t;
    while (t--) {
        cin >> s >> start >> end;
        
        for (int i = 0; i < s.length(); i++) {
            if (start <= i && i < end) continue;
            cout << s[i];
        }
        cout << '\n';
    }

    return 0;
}