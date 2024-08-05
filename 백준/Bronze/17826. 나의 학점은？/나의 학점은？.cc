#include <iostream>
#include <cmath>

using namespace std;

void solution() {
    int scores[50];
    int S, index = 1;

    for (auto &score : scores) {
        cin >> score;
    }
    cin >> S;

    for (int i = 0; i < 50; i++) {
        if (scores[i] == S) {
            index = i + 1;
            break;
        }
    }

    if (index <= 5)
        cout << "A+";
    else if (index <= 15)
        cout << "A0";
    else if (index <= 30)
        cout << "B+";
    else if (index <= 35)
        cout << "B0";
    else if (index <= 45)
        cout << "C+";
    else if (index <= 48)
        cout << "C0";
    else
        cout << "F";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}