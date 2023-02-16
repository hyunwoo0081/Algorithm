#include <iostream>

using namespace std;

void solution() {
    string s;
    int N, count;
    cin >> N >> s;
    count = 1;
    for (int i = 0; i < N; i++) {
        i += s[i] == 'L';
        count++;
    }

    cout << min(N, count);
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}