#include <iostream>
#include <unordered_map>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

unordered_map<string, bool> set;

void solution() {
    int N, M;
    string s;

    cin >> N >> M;
    while (N--) {
        cin >> s;
        set[s] = true;
    }

    int count = 0;
    while (M--) {
        cin >> s;
        if (set[s]) count++;
    }
    cout << count;
}

int main() {
    fastIO();
    solution();

    return 0;
}