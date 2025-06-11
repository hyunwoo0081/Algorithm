#include <iostream>

using namespace std;

int main() {
    char prev = 0;
    string s;
    
    getline(cin, s);
    for (char c : s) {
        if (prev != c)
            cout << c;
        prev = c;
    }
    
    return 0;
}