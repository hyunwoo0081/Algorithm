#include <iostream>

using namespace std;

int main() {
    string s, t="UAPC";
    
    cin >> s;
    
    int j = 0;
    for (int i = 0; i < 4; i++) {
        if (s.length() > j && s[j] == t[i])
            j++;
        else
            cout << t[i];
    }

    return 0;
}