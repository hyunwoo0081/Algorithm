#include <iostream>

using namespace std;


int main() {
    string s;
    char prev = '\0';
    
    cin >> s;
    for (auto c : s) {
        if (prev != c)
            cout << c;
        prev = c;
    }

    return 0;
}