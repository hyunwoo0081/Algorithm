#include <iostream>

using namespace std;

int main() {
    int N, d;
    string s;
    
    cin >> N >> d;
    for (int y = 0; y < N; y++) {
        cin >> s;
        for (auto c : s) {
            if (d == 1) {
                switch(c) {
                    case 'd': cout << 'q'; break;
                    case 'b': cout << 'p'; break;
                    case 'q': cout << 'd'; break;
                    case 'p': cout << 'b'; break;
                    default: cout << c; break;
                }
            }
            else {
                switch(c) {
                    case 'd': cout << 'b'; break;
                    case 'b': cout << 'd'; break;
                    case 'q': cout << 'p'; break;
                    case 'p': cout << 'q'; break;
                    default: cout << c; break;
                }
            }
        }
        cout << '\n';
    }

    return 0;
}