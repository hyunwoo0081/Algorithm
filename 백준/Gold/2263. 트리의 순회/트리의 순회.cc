#include <iostream>
#define SIZE 100000

using namespace std;

int index[SIZE];
int inorder[SIZE];
int postorder[SIZE];

void printTree(int is, int ie, int pr) {
    if (is > ie || pr < 0) return;

    int root = postorder[pr];
    int ir = index[root-1];
    cout << root << ' ';

    printTree(is, ir-1, pr-(ie-ir)-1);
    printTree(ir+1, ie, pr-1);
}

void solution() {
    int N;

    cin >> N;
    for (int n = 0; n < N; ++n) {
        cin >> inorder[n];
        index[inorder[n]-1] = n;
    }
    for (int n = 0; n < N; ++n)
        cin >> postorder[n];

    printTree(0, N-1, N-1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}