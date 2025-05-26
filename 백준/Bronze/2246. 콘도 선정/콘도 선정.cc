#include <iostream>
#define SIZE 10000

using namespace std;

int DC[SIZE][2];

void solution() {
    int N, result = 0;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> DC[i][0] >> DC[i][1];
    }

    for (int i = 0; i < N; i++) {
        bool isValid = true;

        for (int j = 0; j < N; j++) {
            if (i == j) continue;

            isValid &= (DC[i][0] <= DC[j][0] || DC[i][1] < DC[j][1]) && (DC[i][1] <= DC[j][1] || DC[i][0] < DC[j][0]);
        }

        result += isValid;
    }
    cout << result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}