#include <iostream>
#define SIZE 15001
using namespace std;

int getRotationCount(char s[], int len) {
    int cnt = 0, i;
    for (i = 0; i < len; i++) {
        cnt += s[i] - 'A';
    }
    return cnt;
}

char s[SIZE];
void solution() {
    int len, helf, rotate, i, j;

    cin >> s;
    for (len = 0; s[len] != '\0'; len++);
    helf = len / 2;

    // rotate
    rotate = getRotationCount(s, helf) % 26;
    for (i = 0; i < helf; i++) {
        s[i] = (s[i] - 'A' + rotate) % 26 + 'A';
    }

    rotate = getRotationCount(s + helf, len - helf) % 26;
    for (i = helf; i < len; i++) {
        s[i] = (s[i] - 'A' + rotate) % 26 + 'A';
    }

    // marge
    for (i = 0; i < helf; i++) {
        s[i] = (s[i] - 'A' + s[helf + i] - 'A') % 26 + 'A';
    }
    s[i] = '\0';

    cout << s << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}