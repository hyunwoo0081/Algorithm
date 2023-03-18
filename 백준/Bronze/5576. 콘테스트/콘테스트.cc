#include <iostream>
#include <algorithm>

using namespace std;

int a[10], b[10];

void solution() {
    for (int &v : a)
        cin >> v;
    for (int &v : b)
        cin >> v;

    sort(a, a+10);
    sort(b, b+10);

    int sum = 0;
    for (int i = 7; i < 10; i++)
        sum += a[i];
    cout << sum << ' ';

    sum = 0;
    for (int i = 7; i < 10; i++)
        sum += b[i];
    cout << sum;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}