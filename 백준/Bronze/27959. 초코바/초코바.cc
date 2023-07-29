#include <iostream>

using namespace std;

void solution() {
    int N, M;
    cin >> N >> M;
    cout << (N*100 >= M ? "Yes" : "No");
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}