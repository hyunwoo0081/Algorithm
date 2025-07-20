#include <iostream>

using namespace std;

int main() {
    string s;
    int i = 1;
    
    cin >> s;
    for (; i < s.length() && s[i] == s[0]; i++);
    
    cout << i;

    return 0;
}