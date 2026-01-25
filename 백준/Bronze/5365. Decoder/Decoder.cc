#include <iostream>

using namespace std;

int main() {
    int N, prevL = 1;
    string s;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s;
        if (prevL <= s.length()) {
            cout << s[prevL-1];
        }
        else {
            cout << ' ';
        }
        prevL = s.length();
    }

    return 0;
}