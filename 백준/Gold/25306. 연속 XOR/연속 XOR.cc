#include <iostream>
#include <unordered_map>

using namespace std;
typedef long long ll;

unordered_map<ll, bool> visited;

ll bitwise(ll a, ll b) {
    return a&~b|~a&b;
}

void solution() {
    ll A, B, result;
    cin >> A >> B;

    result = -1;
    while (!visited[result] && A <= B) {
        visited[result] = true;
        result = result == -1 ? A : bitwise(result, A);
        A++;
    }

    if (A > B) {
        cout << result;
        return;
    }

    ll count = B - A + 1;
    A += (count/4)*4;

    for (; A <= B; ++A) {
        result = bitwise(result, A);
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