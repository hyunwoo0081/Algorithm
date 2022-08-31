#include <iostream>
#include <vector>

using namespace std;

int normalize(long long n) {
    return n < 0 ? -1 : (n == 0 ? 0 : 1);
}

int ccw(pair<int, int> A, pair<int, int> B, pair<int, int> C) {
    return normalize(((long long) A.first-B.first)*(C.second-B.second)
                    - ((long long) A.second-B.second)*(C.first-B.first));
}

bool isMeet(pair<pair<int, int>, pair<int, int>> A, pair<pair<int, int>, pair<int, int>> B) {
    int a = ccw(A.first, A.second, B.first) * ccw(A.first, A.second, B.second);
    int b = ccw(B.first, B.second, A.first) * ccw(B.first, B.second, A.second);

    if (a == 0 && b == 0) {
        if (A.first > A.second) swap(A.first, A.second);
        if (B.first > B.second) swap(B.first, B.second);

        return !(B.second < A.first || A.second < B.first);
    }
    return a <= 0 && b <= 0;
}

vector<pair<pair<int, int>, pair<int, int>>> lines;
vector<int> unions;
vector<int> counts;

int findRoot(int x) {
    while (unions[x] >= 0)
        x = unions[x];
    return x;
}

void joinUnions(int a, int b) {
    a = findRoot(a);
    b = findRoot(b);

    if (a == b) return;

    if (unions[a] < unions[b]) {
        unions[b] = a;
    }
    else {
        unions[b] = min(unions[a]-1, unions[b]);
        unions[a] = b;
    }
}

void solution() {
    int N, x1, y1, x2, y2;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        lines.emplace_back(make_pair(x1, y1), make_pair(x2, y2));
        unions.push_back(-1);
        counts.push_back(0);

        for (int j = 0; j < i; j++)
            if (isMeet(lines[j], lines[i]))
                joinUnions(j, i);
    }

    for (int i = 0; i < N; i++)
        counts[findRoot(i)]++;

    int count = 0;
    int maxNum = 0;
    for (auto c: counts) {
        count += (c > 0);
        maxNum = max(maxNum, c);
    }

    cout << count << '\n' << maxNum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}