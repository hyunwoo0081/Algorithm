#include <iostream>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define SIZE 10000

using namespace std;

int edges[SIZE][2];
int leftNode[SIZE] = {0};
int rightNode[SIZE] = {0};
bool isNotNode[SIZE] = {false};

int findOwnPosition(int node, int parentPosition, int depth) {
    int ownPosition = parentPosition;
    int nodeCounts = 0;

    if (edges[node][0] >= 0)
        nodeCounts = findOwnPosition(edges[node][0], ownPosition, depth+1);
    ownPosition += nodeCounts+1;

    if (leftNode[depth] == -1 || leftNode[depth] > ownPosition)
        leftNode[depth] = ownPosition;
    if (rightNode[depth] == -1 || rightNode[depth] < ownPosition)
        rightNode[depth] = ownPosition;

    if (edges[node][1] >= 0)
        nodeCounts += findOwnPosition(edges[node][1], ownPosition, depth + 1);

    return nodeCounts + 1;
}

void solution() {
    int N, node, left, right, root;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> node >> left >> right;
        edges[node-1][0] = left-1;
        edges[node-1][1] = right-1;
        isNotNode[left-1] = isNotNode[right-1] = true;

        leftNode[i] = rightNode[i] = -1;
    }

    for (int i = 0; i < N; ++i)
        if (!isNotNode[i]) root = i;

    findOwnPosition(root, 0, 0);

    int maxIndex = 0, maxValue = 0;
    for (int i = 0; i < N; ++i) {
        if (maxValue < rightNode[i]-leftNode[i]+1) {
            maxIndex = i;
            maxValue = rightNode[i]-leftNode[i]+1;
        }
    }

    cout << maxIndex+1 << ' ' << maxValue;
}

int main() {
    fastIO();
    solution();

    return 0;
}