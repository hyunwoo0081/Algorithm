#include <iostream>

using namespace std;

char o[] = {'a', 'e', 'i', 'o', 'u'};
bool isO(char c) {
    for (auto i : o) {
        if (c == i) return true;
    }
    return false;
}

int main() {
    string s;
    bool result = true;
    
    cin >> s;
    for (int i = 1; i < s.length(); i++) {
        result &= isO(s[i-1]) != isO(s[i]);
    }
    cout << result;

    return 0;
}