#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, double> costs;

void solution() {
    int N, a, cnt = 0;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a;
        cnt += a;
    }

    cout << min(N-cnt, cnt);

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}