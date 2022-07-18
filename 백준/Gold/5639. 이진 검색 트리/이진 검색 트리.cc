#include <iostream>

using namespace std;

int solution(int left, int right, int n) {
    int rn = -1;
    if (n > 0 || cin >> n) {
        if (left < n && n < right)
            rn = solution(0, n, -1);
        else
            return n;

        if (n < rn && rn < right)
            rn = solution(n, right, rn);

        cout << n << '\n';
        return rn;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution(0, 987654321, -1);

    return 0;
}