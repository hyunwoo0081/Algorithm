#include <iostream>
#include <vector>
#include <stack>
#define SIZE 123

using namespace std;

bool isFirst[SIZE] = {false};
stack<int> leftStack;
stack<int> rightStack;
vector<int> result;

void solution() {
    int N, a;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a;
        leftStack.push(a);
        isFirst[a-1] = true;
    }

    for (int i = N; i > 0; i--) {
        if (isFirst[i-1]) {
            a = leftStack.top();
            while (a != i) {
                rightStack.push(a);
                leftStack.pop();
                isFirst[a-1] = false;

                result.push_back(1);
                result.push_back(2);

                a = leftStack.top();
            }

            leftStack.pop();
            result.push_back(1);
        } else {
            a = rightStack.top();
            while (a != i) {
                leftStack.push(a);
                rightStack.pop();
                isFirst[a-1] = true;

                result.push_back(2);
                result.push_back(1);

                a = rightStack.top();
            }

            rightStack.pop();
            result.push_back(2);
        }

        result.push_back(3);
        isFirst[i-1] = false;
    }

    a = 0;
    cout << result.size()/2 << '\n';
    for (const auto v : result) {
        cout << v << (++a % 2 ? ' ' : '\n');
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}