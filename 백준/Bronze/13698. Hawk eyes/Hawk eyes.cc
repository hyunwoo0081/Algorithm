#include <iostream>

using namespace std;

int shakes[6][2];

int main() {
    string s;
    int a[4] = {1,2,3,4};
    int k = 0;
    
    for (int i = 0; i < 4-1; i++)
        for (int j = i+1; j < 4; j++) {
            shakes[k][0] = i;
            shakes[k++][1] = j;
        }
        
    cin >> s;
    for (auto c : s) {
        k = a[shakes[c-'A'][0]];
        a[shakes[c-'A'][0]] = a[shakes[c-'A'][1]];
        a[shakes[c-'A'][1]] = k;
    }
    
    for (int i = 0; i < 4; i++) {
        if (a[i] == 1) cout << i+1 << '\n';
    }
    
    for (int i = 0; i < 4; i++) {
        if (a[i] == 4) cout << i+1;
    }

    return 0;
}