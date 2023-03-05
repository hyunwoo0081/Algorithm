#include <iostream>

using namespace std;

void solution() {
    int N, M, J, apple, left, right, count;

    cin >> N >> M >> J;
    left = 1;
    right = left + M - 1;
    count = 0;
    while (J--) {
        cin >> apple;
        if (apple < left) {
            count += left - apple;
            left = apple;
            right = left + M - 1;
        }
        else if (right < apple) {
            count += apple - right;
            right = apple;
            left = right - M + 1;
        }
    }
    cout << count;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}