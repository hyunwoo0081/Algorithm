#include <iostream>
#include <vector>
#define SIZE 100000
using namespace std;

vector<int> edges[SIZE];
int subTreeCounts[SIZE] = {0};

int makeTree(int R) {
    if (subTreeCounts[R]) return 0;

    subTreeCounts[R] = 1;
    for (auto edge: edges[R])
        subTreeCounts[R] += makeTree(edge);

    return subTreeCounts[R];
}

void solution() {
    int N, R, Q, U, V;

    cin >> N >> R >> Q;
    for (int i = 0; i < N-1; i++) {
        cin >> U >> V;
        U--, V--;
        edges[U].push_back(V);
        edges[V].push_back(U);
    }

    makeTree(R-1);

    while (Q--) {
        cin >> U;
        cout << subTreeCounts[U-1] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}