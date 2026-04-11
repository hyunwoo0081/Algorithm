#include <iostream>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, ch=0, nch;
    string s;
    
    cin >> N >> s;
    
    
    for (auto c : s) {
        ch += c == 'C';
    }
    nch = N-ch+1;
    
    cout << (int)(ch / nch) + (ch % nch != 0);

    return 0;
}