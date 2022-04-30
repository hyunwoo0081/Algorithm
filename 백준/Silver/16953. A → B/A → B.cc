#include <iostream>
#include <queue>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

queue<pair<int, long long>> q;

int getCount(int A, int B) {
    long long num;
    int index;
    q.emplace(1, A);

    while (!q.empty()) {
        index = q.front().first;
        num = q.front().second;
        q.pop();

        if (num > B) continue;
        if (num == B) return index;
        q.emplace(index+1, num*2);
        q.emplace(index+1, num*10 + 1);
    }

    return -1;
}

void solution() {
    int A, B;

    cin >> A >> B;
    cout << getCount(A, B);
}

int main() {
    fastIO();
    solution();

    return 0;
}