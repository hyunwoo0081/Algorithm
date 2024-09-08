#include <iostream>

using namespace std;

char words[] = {'I', 'O', 'S', 'H', 'Z', 'X', 'N'};

int main() {
    string s;
    bool isRotate = true, included;
    
    cin >> s;
    for (auto c : s) {
        included = false;
        for (auto i : words)
            included |= c == i;
        
        isRotate &= included;
    }
    
    cout << (isRotate ? "YES" : "NO");

    return 0;
}