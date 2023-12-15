#include <iostream>

using namespace std;

void solution() {
    int K, a, b;
    cin >> K >> a >> b;
    K = K % (a+b);
    cout << (int)(K < a);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}