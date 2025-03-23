#include <iostream>

using namespace std;

void solution() {
    int a, b, s3, s2, s1;

    cin >> s3 >> s2 >> s1;
    a = 3*s3 + 2*s2 + s1;

    cin >> s3 >> s2 >> s1;
    b = 3*s3 + 2*s2 + s1;

    if (a > b) {
        cout << "A";
    } else if (a < b) {
        cout << "B";
    } else {
        cout << "T";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}