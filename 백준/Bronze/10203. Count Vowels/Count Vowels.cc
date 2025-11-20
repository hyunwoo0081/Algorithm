#include <iostream>

using namespace std;

string vowel = "aeiou";
int main() {
    int N, r;
    string s;
    
    cin >> N;
    while (N--) {
        cin >> s;
        
        r = 0;
        for (auto c : s) {
            for (auto v : vowel) {
                r += c == v;
            }
        }
        
        cout << "The number of vowels in " << s << " is " << r << ".\n";
    }

    return 0;
}