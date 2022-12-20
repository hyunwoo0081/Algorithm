#include <iostream>
#include <vector>

using namespace std;

vector<char> leftS;
vector<char> rightS;

void solution() {
    int N;
    string s;

    cin >> N;
    while (N--) {
        cin >> s;
        leftS.clear();
        rightS.clear();

        for (auto c : s) {
            if (c == '<') {
                if (leftS.empty())
                    continue;
                rightS.push_back(leftS.back());
                leftS.pop_back();
            }
            else if (c == '>') {
                if (rightS.empty())
                    continue;
                leftS.push_back(rightS.back());
                rightS.pop_back();
            }
            else if (c == '-') {
                if (leftS.empty())
                    continue;
                leftS.pop_back();
            }
            else
                leftS.push_back(c);
        }
        for (auto c: leftS)
            cout << c;
        while (!rightS.empty()) {
            cout << rightS.back();
            rightS.pop_back();
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