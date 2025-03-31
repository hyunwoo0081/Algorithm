#include <iostream>
#include <algorithm>
#define SIZE 9

using namespace std;

void solution() {
    int score[SIZE], ranks[SIZE] = {0}, sortScore[SIZE];
    int R, C;
    string s;

    cin >> R >> C;
    for (int i = 0; i < R; i++)
    {
        cin >> s;

        for (int j = 0; j < C; j++) {
            if ('1' <= s[j] && s[j] <= '9') {
                int num = s[j] - '1';
                score[num] = j;
                sortScore[num] = j;
                break;
            }
        }
    }

    sort(sortScore, sortScore+SIZE, greater<int>());

    int rank = 1;
    for (int i = 0; i < SIZE; i++) {
        if (i < SIZE - 1 && sortScore[i] == sortScore[i + 1]) {
            continue;
        }

        for (int j = 0; j < SIZE; j++) {
            if (sortScore[i] == score[j]) {
                ranks[j] = rank;
            }
        }
        rank++;
    }

    for (auto i : ranks) {
        cout << i << "\n";
    }
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}