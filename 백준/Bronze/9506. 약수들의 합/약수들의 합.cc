#include <iostream>
#include <vector>

using namespace std;

vector<int> stack;

void solution() {
    int N, sum;

    stack.reserve(100000);

    cin >> N;
    while (N != -1) {
        stack.clear();

        sum = 0;
        for (int k = 1; k < N; k++)
            if (N % k == 0) {
                sum += k;
                stack.push_back(k);
            }

        if (N == sum) {
            cout << N << " = 1";
            for (int i = 1; i < stack.size(); i++)
                cout << " + " << stack[i];
        }
        else {
            cout << N << " is NOT perfect.";
        }
        cout << '\n';

        cin >> N;
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}