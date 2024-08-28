#include <iostream>

using namespace std;

char arr[] = {'p', 'P', 'A', 'p'};
int main() {
    int N, i, cnt = 0;
    string s;
    
    cin >> N >> s;
    i = 0;
    for (auto c: s) {
        if (arr[i] != c) i = 0;
        
        if (arr[i] == c) i++;
        else i = 0;
        
        if (i == 4) {
            i = 0;
            cnt++;
        }
    }
    
    cout << cnt;

    return 0;
}