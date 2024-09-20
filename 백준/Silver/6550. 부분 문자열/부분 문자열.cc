// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;

int main() {
    string s, t;
    int ls, lt;
    bool isSame;
    
    while(cin >> s >> t) {
        ls = s.size();
        lt = t.size();
        
        int j = 0;
        for (int i = 0; i < lt && j < ls; i++) {
            if (t[i] == s[j]) {
                j++;
            }
        }
        
        isSame = j == ls;
        
        cout << (isSame ? "Yes\n" : "No\n");
    }

    return 0;
}