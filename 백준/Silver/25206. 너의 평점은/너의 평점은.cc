#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, double> scoreMap;

void solution() {
    string s, score;
    double sum, n, a;

    scoreMap["A+"] = 4.5;
    scoreMap["A0"] = 4.0;
    scoreMap["B+"] = 3.5;
    scoreMap["B0"] = 3.0;
    scoreMap["C+"] = 2.5;
    scoreMap["C0"] = 2.0;
    scoreMap["D+"] = 1.5;
    scoreMap["D0"] = 1.0;
    scoreMap["F"] = 0.0;

    sum = n = 0;
    for (int i = 0; i < 20; i++) {
        cin >> s >> a >> score;

        if (score[0] == 'P') continue;

        n += a;
        sum += scoreMap[score] * a;
    }

    cout << sum / n;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}