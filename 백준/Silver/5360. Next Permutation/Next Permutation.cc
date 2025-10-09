#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int T;
    string s;
    char c;
    
    cin >> T;
    while (T--) {
        cin >> s;
        
        auto i = s.end()-1;
        for (; i != s.begin(); i--) {
            if (*(i-1) < *(i)) break;
        }
        
        if (i == s.begin()) {
            cout << "USELESS\n";
            continue;
        }
        
        
        auto target = i;
        for (auto j = i; j < s.end(); j++) {
            if (*(i-1) < *j && *j < *target) {
                target = j;
            }
        }
        
        // swap
        c = *target;
        *target = *(i-1);
        *(i-1) = c;
        
        // sort
        sort(i, s.end());
        
        cout << s << '\n';
    }

    return 0;
}