#include <iostream>

using namespace std;

int main() {
    string s, t;
    int n, result = 0;
    
    cin >> s >> n;
    string sub = s.substr(0, 5);
    while (n--) {
        cin >> t;
        result += sub == t.substr(0, 5);
    }
    cout << result;

    return 0;
}