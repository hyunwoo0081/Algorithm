#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

void solution() {
    int packet, N;


    cin >> N >> packet;
    while (packet != -1) {
        if (packet == 0)
            q.pop();
        else if(q.size() < N)
            q.push(packet);

        cin >> packet;
    }

    if (q.empty())
        cout << "empty";
    else
        while (!q.empty()) {
            cout << q.front() << ' ';
            q.pop();
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();

    return 0;
}
