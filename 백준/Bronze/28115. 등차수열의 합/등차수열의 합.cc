#include <iostream>

using namespace std;

int seq[100000] = {};

void solution() {
    int N, a;
    bool isSeq;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> seq[i];

    isSeq = true;
    a = seq[1]-seq[0];
    for (int i = 2; i < N && isSeq; i++)
        if (seq[i]-seq[i-1] != a)
            isSeq = false;

    if (isSeq) {
        cout << "YES\n";
        for (int i = 0; i < N; i++)
            cout << seq[i] << ' ';
        cout << '\n';
        for (int i = 0; i < N; i++)
            cout << "0 ";
    }
    else {
        cout << "NO\n";
    }

}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}