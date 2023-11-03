#include <iostream>

using namespace std;

void solution() {
    int s1, s2, res, ans;
    bool sample, test;

    cin >> s1 >> s2;
    sample = test = true;
    while (s1--) {
        cin >> res >> ans;
        sample &= res == ans;
    }
    while (s2--) {
        cin >> res >> ans;
        test &= res == ans;
    }

    if (sample && test)
        cout << "Accepted";
    else if (!sample)
        cout << "Wrong Answer";
    else
        cout << "Why Wrong!!!";
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}