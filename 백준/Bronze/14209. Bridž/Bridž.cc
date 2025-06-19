#include <iostream>

using namespace std;

int main() {
    int N, score = 0;
    string s;
    
    cin >> N;
    while (N--) {
        cin >> s;
        for (auto c : s) {
            if (c == 'A') score += 4;
            else if (c == 'K') score += 3;
            else if (c == 'Q') score += 2;
            else if (c == 'J') score += 1;
        }
    }
    
    cout << score;

    return 0;
}