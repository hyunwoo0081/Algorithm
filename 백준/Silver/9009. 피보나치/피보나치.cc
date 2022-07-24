#include <iostream>
#include <vector>

using namespace std;

int fibo[46];
vector<int> stack;

void solution() {
    int n, x;

    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i < 46; i++)
        fibo[i] = fibo[i-1] + fibo[i-2];

    cin >> n;
    while (n--) {
        cin >> x;
        stack.clear();
        for (int i = 45; i > 0 && x > 0; i--) {
            if (x < fibo[i]) continue;
            x -= fibo[i];
            stack.push_back(fibo[i]);
        }

        for (int i = stack.size()-1; i >= 0; i--) {
            cout << stack[i] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}