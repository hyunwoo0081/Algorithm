#include <iostream>

using namespace std;

void solution() {
    int T, score;
    string s;

    cin >> T;
    while (T--) {
        cin >> s >> score;

        cout << s << ' ';
        if (score >= 97)
            cout << "A+";
        else if (score >= 90)
            cout << "A";
        else if (score >= 87)
            cout << "B+";
        else if (score >= 80)
            cout << "B";
        else if (score >= 77)
            cout << "C+";
        else if (score >= 70)
            cout << "C";
        else if (score >= 67)
            cout << "D+";
        else if (score >= 60)
            cout << "D";
        else
            cout << "F";
        cout << "\n";
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}