#include <iostream>
#include <vector>

using namespace std;

vector<char> stack;

void solution() {
    int N, K;
    string s;

    stack.reserve(500000);
    cin >> N >> K >> s;
    for (auto c : s) {
        while (K > 0 && !stack.empty() && stack.back() < c) {
            stack.pop_back();
            K--;
        }
        stack.push_back(c);
    }

    while (K--)
        stack.pop_back();

    for (auto c: stack)
        cout << c;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}