#include <iostream>

using namespace std;

int results[512];

int clicks[9];

void makeClicks() {
    for (int i = 0; i < 9; i++) {
        clicks[i] = 0;

        for (int j = 0; j < 9; j++) {
            bool isChecked = i%3==j%3 && abs(i/3-j/3) <= 1 || i/3==j/3 && abs(i-j) <= 1;
            clicks[i] = (clicks[i] << 1) + isChecked;
        }
    }
}

void makeResults(int result, int cnt, int depth) {
    if (depth == 9) {
        results[result] = cnt;
        return;
    }

    makeResults(result, cnt, depth+1);
    makeResults(result ^ clicks[depth], cnt+1, depth+1);
}

void solution() {
    int Q;
    string s;

    makeClicks();
    makeResults(0, 0, 0);

    cin >> Q;
    while (Q--) {
        int result = 0;
        for (int i = 0; i < 3; i++) {
            cin >> s;
            for (int j = 0; j < 3; j++) {
                result = (result << 1) + (s[j] == '*');
            }
        }

        cout << results[result] << '\n';
    }
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}