#include <iostream>

using namespace std;

int p[5][3] = {0};

int main() {
    int N;
    string s;
    
    cin >> N;
    while (N--) {
        cin >> s;
        p[s[0]-'1'][s[1]-'A']++;
    }
    
    bool result = true;
    for (int r = 0; r < 5; r++) {
        for (int d = 0; d < 3; d++) {
            result &= (p[r][d] >= 1 + (r==4));
        }
    }
    
    cout << (result ? "TAK" : "NIE");

    return 0;
}