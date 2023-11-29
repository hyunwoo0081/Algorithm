#include <iostream>

using namespace std;

void solution() {
    int N;

    cin >> N;
    if (380 <= N && N < 425)
        cout << "Violet";
    else if (N < 450)
        cout << "Indigo";
    else if (N < 495)
        cout << "Blue";
    else if (N < 570)
        cout << "Green";
    else if (N < 590)
        cout << "Yellow";
    else if (N < 620)
        cout << "Orange";
    else if (N <= 780)
        cout << "Red";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}