#include <iostream>
#define NO_WINNER (-1)

using namespace std;

void solution() {
    long long T, N, num, sum, winner, maxNum;

    cin >> T;
    while (T--) {
        cin >> N;

        winner = NO_WINNER;
        maxNum = 0;
        sum = 0;
        for (int i = 1; i <= N; i++) {
            cin >> num;

            sum += num;
            if (maxNum < num) {
                maxNum = num;
                winner = i;
            } else if (maxNum == num) {
                winner = NO_WINNER;
            }
        }

        if (winner == NO_WINNER) {
            cout << "no winner" << '\n';
        } else if (sum < 2*maxNum) {
            cout << "majority winner " << winner << '\n';
        } else {
            cout << "minority winner " << winner << '\n';
        }
    }


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}