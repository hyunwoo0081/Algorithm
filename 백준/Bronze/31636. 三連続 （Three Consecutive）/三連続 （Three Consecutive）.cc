#include <iostream>

using namespace std;

int main() {
    string s;
    int start = -1, result = 0, N;
    
    cin >> N >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'x')
            start = i;
        result = max(result, i-start);
    }
    
    cout << (result >= 3 ? "Yes" : "No");

    return 0;
}