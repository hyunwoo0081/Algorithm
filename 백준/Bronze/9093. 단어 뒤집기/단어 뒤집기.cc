#include <iostream>
#include <vector>

using namespace std;

vector<char> stack;

void solution() {
    string s;
    int N;

    cin >> N;
    cin.ignore();
    while (N--) {
        getline(cin, s);

        for (auto c:s) {
            if (c == ' ') {
                while (!stack.empty()) {
                    cout << stack.back();
                    stack.pop_back();
                }
                cout << ' ';
            }
            else
                stack.push_back(c);
        }

        while (!stack.empty()) {
            cout << stack.back();
            stack.pop_back();
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