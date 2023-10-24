#include <iostream>

using namespace std;

void solution() {
    int N;
    cin >> N;
    if (N%2 == 1)
        cout << "Either";
    else if (N%4 == 2)
        cout << "Odd";
    else
        cout << "Even";
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}