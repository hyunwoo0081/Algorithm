#include <iostream>

using namespace std;

int main() {
    int X, Y, K, result = 0;
    string s;
    
    cin >> Y >> X >> K;
    for (int y = 0; y < Y; y++) {
        cin >> s;
        for (int x = 0; x <= X-K; x++) {
            bool isPos = true;
            for (int i = 0; i < K; i++)
                isPos &= s[x+i] == '0';
            result += isPos;
        }
    }
    cout << result;

    return 0;
}