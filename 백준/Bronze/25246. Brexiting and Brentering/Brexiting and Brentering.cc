#include <iostream>

using namespace std;

char targets[] = {'a', 'i', 'u', 'e', 'o'};

int main() {
    string s;
    int d = 0;
    
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        for (auto c : targets)
            if (s[i] == c) d = i;
    }
    
    for (int i = 0; i <= d; i++)
        cout << s[i];
    cout << "ntry";

    return 0;
}