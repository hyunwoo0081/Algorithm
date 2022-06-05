#include <iostream>
#include <stack>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

stack<int> s[6];

void solution() {
    int N, P, n, p, count;

    count = 0;
    cin >> N >> P;
    while (N--) {
        cin >> n >> p;
        n--;
        while (!s[n].empty() && s[n].top() > p) {
            s[n].pop();
            count++;
        }

        if (s[n].empty() || s[n].top() < p) {
            s[n].push(p);
            count++;
        }
    }
    cout << count;
}

int main() {
    fastIO();
    solution();

    return 0;
}