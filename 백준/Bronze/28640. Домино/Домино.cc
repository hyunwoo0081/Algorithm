#include <iostream>

using namespace std;

int main() {
    string s;
    int ind;
    int a[] = {0, 0};
    int b[] = {0, 0};
    
    ind = 0;
    cin >> s;
    for (auto c : s) {
        if (c == '|') {
            ind = 1;
            continue;
        }
        a[ind]++;
    }
    
    ind = 0;
    cin >> s;
    for (auto c : s) {
        if (c == '|') {
            ind = 1;
            continue;
        }
        b[ind]++;
    }
    
    cout << (a[0] == b[0] || a[1] == b[1] || a[0] == b[1] || a[1] == b[0] ? "Yes" : "No");

    return 0;
}