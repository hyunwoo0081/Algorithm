#include <iostream>

using namespace std;

int main() {
    int n;
    bool result = true;
    string s;
    
    cin >> n >> s;
    for (int i = 1; i < n*2; i++)
        result &= s[i-1] != s[i];
    cout << (result ? "Yes" : "No");

    return 0;
}