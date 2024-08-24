#include <iostream>
#define SIZE 26

using namespace std;

int main() {
    int T;
    int cnts[SIZE];
    string s;
    
    cin >> T;
    while (T--) {
        cin >> s;
        
        for (auto &a : cnts)
            a = 0;
        
        for (auto c : s) {
            if ('a' <= c && c <= 'z')
                cnts[c-'a']++;
            else if ('A' <= c && c <= 'Z')
                cnts[c-'A']++;
        }
        
        int i = 0, j = SIZE-1;
        while (i < j && cnts[i] == cnts[j]) {
            i++, j--;
        }
        bool isSame = !(i < j);

        cout << (isSame ? "Yes\n" : "No\n");
    }
    
    return 0;
}