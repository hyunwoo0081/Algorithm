#include <iostream>
#define SIZE 50000

using namespace std;

int backs[SIZE] = {0};
int main() {
    int N, i, cnt;
    string s;
    
    cin >> s;
    N = s.length();
    for (i = N-1; i >= 0; i--) {
        if (s[i] == s[i+1] && s[i] == ')')
            backs[i] = backs[i+1] + 1;
        else
            backs[i] = backs[i+1];
    }
    
    cnt = 0;
    for (i = 0; i < N-1; i++) {
        if (s[i] == s[i+1] && s[i] == '(') 
            cnt += backs[i];
    }
    
    cout << cnt;

    return 0;
}