#include <iostream>

using namespace std;

void solution() {
    string s;

    cout << "Latitude ";
    for (int i = 0; i < 3; i++) {
        if (i != 0)
            cout << ':';
        getline(cin, s);
        cout << s.length() - (s[s.length()-1] == ' ');
    }
    cout << '\n';

    cout << "Longitude ";
    for (int i = 0; i < 3; i++) {
        if (i != 0)
            cout << ':';
        getline(cin, s);
        cout << s.length() - (s[s.length()-1] == ' ');
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}