#include <iostream>

using namespace std;

string target = "CAMBRIDGE";
bool masks[26] = {false};
int main() {
    string s;
    
    for (auto c : target) {
        masks[c-'A'] = true;
    }
    
    cin >> s;
    for (auto c : s) {
        if (!masks[c-'A']) {
            cout << c;
        }
    }

    return 0;
}