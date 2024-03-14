#include <iostream>

using namespace std;

void solution() {
    int N, s1, s2;
    char c;

    cin >> N;
    s1 = s2 = 0;
    while (N--) {
        cin >> c;
        if (s1-s2 >= 2 || s1-s2 <= -2)
            break;
        s1 += c == 'D';
        s2 += c == 'P';
    }

    cout << s1 << ':' << s2;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}