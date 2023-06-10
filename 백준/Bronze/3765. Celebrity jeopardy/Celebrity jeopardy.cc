#include <iostream>

using namespace std;

void solution() {
    string s;

    while(getline(cin, s, '\n'))
        cout << s << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}