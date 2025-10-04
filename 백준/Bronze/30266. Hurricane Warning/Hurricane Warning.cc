#include <iostream>

using namespace std;

bool chk[26];
int main() {
    int T, N, r;
    string s;
    
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N >> s;
        for (auto &c : chk) c = false;
        for (auto c : s) chk[c-'A'] = true;
        
        r = 0;
        while (N--) {
            cin >> s;
            bool called = false;
            for (auto c : s) called |= chk[c-'A'];
            r += called;
        }
        
        cout << "Data Set " << t << ":\n" << r << "\n\n";
    }

    return 0;
}