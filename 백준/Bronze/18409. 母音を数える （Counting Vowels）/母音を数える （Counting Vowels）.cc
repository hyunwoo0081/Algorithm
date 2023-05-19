#include <iostream>

using namespace std;

void solution() {
    int N, count = 0;
    string s;

    cin >> N >> s;
    for (auto c : s)
        count += c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o';
    cout << count;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}