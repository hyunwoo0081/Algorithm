#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> results;

void solution() {
    int N;

    for (int a = 10; a <= 99; a++) {
        for (int b = 0; b <= 99; b++) {
            int num = a * 100 + b;

            if (num == (a + b) * (a + b)) {
                results.push_back(num);
            }
        }
    }

    sort(results.begin(), results.end());

    cin >> N;
    for (const auto result : results) {
        if (result > N) {
            cout << result << '\n';
            break;
        }
    }

    if (N >= results.back())
        cout << -1;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}