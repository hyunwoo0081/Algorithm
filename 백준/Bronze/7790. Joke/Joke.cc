#include <iostream>

using namespace std;

int main() {
    int j, result = 0;
    string joke = "joke";
    string s;

    while (cin >> s) {
        int len = s.length()-4+1;
        
        for (int i = 0; i < len; i++) {
            for (j = 0; j < 4 && joke[j] == s[i+j]; j++) {}
            result += j == 4;

            // i += j;
        }
    }
    cout << result;

    return 0;
}