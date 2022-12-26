#include <iostream>
#include <vector>

using namespace std;

void solution() {
    vector<char> stack;
    string s;

    cin >> s;
    for (auto c : s) {
        if ('A' <= c && c <= 'Z') {
            cout << c;
        }
        else {
            if (c == ')') {
                while (stack.back() != '(') {
                    cout << stack.back();
                    stack.pop_back();
                }
                stack.pop_back();
            }
            else if (c == '(')
                stack.push_back(c);
            else if (c == '+' || c == '-') {
                while (!stack.empty() && stack.back() != '(') {
                    cout << stack.back();
                    stack.pop_back();
                }
                stack.push_back(c);
            }
            else {
                while (!stack.empty() && stack.back() != '(' && stack.back() != '+' && stack.back() != '-') {
                    cout << stack.back();
                    stack.pop_back();
                }
                stack.push_back(c);
            }
        }
    }
    while (!stack.empty()) {
        cout << stack.back();
        stack.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}