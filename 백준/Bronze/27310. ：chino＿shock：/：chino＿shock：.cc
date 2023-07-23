#include <iostream>

using namespace std;

void solution() {
    string s;
    int count = 0;

    cin >> s;
    for (auto c: s) {
        if (c == '_')
            count += 6;
        else if(c == ':')
            count += 2;
        else
            count++;
    }
    cout << count;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}