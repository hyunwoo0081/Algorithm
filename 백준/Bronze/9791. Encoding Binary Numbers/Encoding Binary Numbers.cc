#include <iostream>

using namespace std;

int main() {
    string s;
    int cnt = -1;
    char prevC = '\0';
    
    cin >> s;
    while (s != "0") {
        prevC = '\0';
        cnt = -1;
        for (auto c : s) {
            if (prevC != c) {
                if (prevC != '\0') {
                    cout << cnt << prevC;
                }
                
                prevC = c;
                cnt = 1;
            }
            else {
                cnt++;
            }
        }
        cout << cnt << prevC << '\n';
        cin >> s;
    }
    
    return 0;
}