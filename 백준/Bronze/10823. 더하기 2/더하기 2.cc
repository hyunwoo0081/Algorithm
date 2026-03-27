#include <iostream>

using namespace std;

int main() {
    string s;
    
    long long result = 0;
    long long n = 0;
    while (getline(cin, s)) {
        for (auto c : s) {
            if ('0' <= c && c <= '9') {
                n = 10*n + c-'0';
            }
            else if (c == ',') {
                result += n;
                n = 0;
            }
        }
    }
    result += n;
    
    cout << result;

    return 0;
}