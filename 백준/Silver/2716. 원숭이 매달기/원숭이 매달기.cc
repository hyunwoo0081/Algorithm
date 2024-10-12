#include <iostream>

using namespace std;

void solution() {
    int T, depth, maxDepth;
    string s;

    cin >> T;
    cin.ignore();
    while (T--) {
        getline(cin, s);
        depth = maxDepth = 0;

        for (auto c : s) {
            depth += (c == '[' ? 1 : -1);
            maxDepth = max(maxDepth, depth);
        }

        cout << (1 << maxDepth) << '\n';
    }

}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}