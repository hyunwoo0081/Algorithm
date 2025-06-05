#include <iostream>

using namespace std;

int main() {
    int result = 1;
    string s1, s2;
    
    cin >> s1 >> s2;
    for (int i = 0; i < 4; i++) {
        result *= (s1[i] != s2[i]) + 1;
    }
    cout << result;

    return 0;
}