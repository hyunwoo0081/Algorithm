#include <iostream>
#define SIZE 1'000'000
#define ll long long

using namespace std;

ll tree[SIZE*4];
ll lazy[SIZE*4] = {0};

ll bulkInputs(int node, int start, int end) {
    if (start == end) {
        cin >> tree[node];
        return tree[node];
    }
    
    int mid = (start + end) / 2;
    return tree[node] = bulkInputs(node*2, start, mid) + bulkInputs(node*2+1, mid+1, end);
}

// 현재 노드 갱신 + 다음 노드에 전파
void propagate(int node, int start, int end) {
    if (lazy[node] != 0) {
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end) { // 마지막 노드가 아니면
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
    }
    lazy[node] = 0;
}

ll getQuery(int node, int start, int end, int left, int right) {
    if (end < left || right < start) return 0;
    propagate(node, start, end);
    if (left <= start && end <= right) return tree[node];
    
    int mid = (start + end) / 2;
    return getQuery(node*2, start, mid, left, right) + getQuery(node*2+1, mid+1, end, left, right);
}

void updateQuery(int node, int start, int end, int left, int right, ll diff) {
    propagate(node, start, end);
    
    if (end < left || right < start) return;
    if (left <= start && end <= right) {
        lazy[node] += diff;
        propagate(node, start, end);
        return;
    }
    
    int mid = (start + end) / 2;
    updateQuery(node*2, start, mid, left, right, diff);
    updateQuery(node*2+1, mid+1, end, left, right, diff);
    tree[node] = tree[node*2] + tree[node*2+1];
}

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M, K, cmd, from, to;
    ll diff;
    
    cin >> N >> M >> K;
    bulkInputs(1, 1, N);
    
    for (int i = 0; i < M+K; i++) {
        cin >> cmd;
        if (cmd == 1) {
            cin >> from >> to >> diff;
            updateQuery(1, 1, N, from, to, diff);
        }
        else {
            cin >> from >> to;
            cout << getQuery(1, 1, N, from, to) << '\n';
        }
    }

    return 0;
}