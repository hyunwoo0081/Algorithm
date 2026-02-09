#include <iostream>

using namespace std;

int main() {
    int N, L, r, maxNum=0, cnt=0;
    string s;
    char prev;
    
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        cin >> s;
        
        prev = '0';
        r = 0;
        for (auto c : s) {
            if (prev == '0' && c == '1') {
                r++;
            }
            
            prev = c;
        }
        
        if (maxNum < r) {
            maxNum = r;
            cnt = 1;
        }
        else if (maxNum == r) {
            cnt++;
        }
    }
    
    cout << maxNum << ' ' << cnt;

    return 0;
}