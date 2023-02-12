#include <iostream>
#include <vector>

using namespace std;

vector<int> stack;

void printNums(int visited, int N) {
    if (visited == (1<<N)-1) {
        for (auto v: stack)
            cout << v << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!(visited & (1<<i))) {
            stack.push_back(i+1);
            printNums(visited | (1<<i), N);
            stack.pop_back();
        }
    }
}

void solution() {
    int N;
    cin >> N;
    printNums(0, N);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}