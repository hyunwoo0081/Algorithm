#include <iostream>

using namespace std;

int main() {
    char c;
    int N, a, b, i, j;
    char s[201];
    
    cin >> N >> a >> b >> s;
    
    i = a-1;
    j = b-1;
    while (i < j) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
        
        i++, j--;
    }
    
    cout << s;

    return 0;
}