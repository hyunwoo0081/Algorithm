#include <iostream>

using namespace std;

int main() {
    string s;
    int left, right;
    
    cin >> right >> s;
    right--;
    
    for (left = 0; left < s.length(); left++) {
        if (s[left] != '?') {
            cout << s[left];
        }
        else if (s[right] == '?') {
            cout << 'a';
        }
        else {
            cout << s[right];
        }
        
        right--;
    }

    return 0;
}