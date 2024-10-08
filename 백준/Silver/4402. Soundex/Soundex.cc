#include <iostream>

using namespace std;

int main() {
    string s;
    int prev, now;
    
    while (cin >> s) {
        prev = -1;
        
        for (auto c : s) {
            switch(c) {
                case 'B': case 'F': case 'P': case 'V':
                    now = 1;
                    break;
                case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z':
                    now = 2;
                    break;
                case 'D': case 'T':
                    now = 3;
                    break;
                case 'L':
                    now = 4;
                    break;
                case 'M': case 'N':
                    now = 5;
                    break;
                case 'R':
                    now = 6;
                    break;
                default:
                    now = -1;
            }
            
            if (prev != now) {
                prev = now;
                if (now > 0)
                    cout << now;
            }
        }
        
        cout << '\n';
    }

    return 0;
}