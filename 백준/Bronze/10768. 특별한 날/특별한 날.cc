#include <iostream>

using namespace std;

void solution() {
    int A, B;

    cin >> A >> B;
    if (A == 2 && B == 18)
        cout << "Special";
    else if(A == 2 && B < 18 || A < 2)
        cout << "Before";
    else
        cout << "After";
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}