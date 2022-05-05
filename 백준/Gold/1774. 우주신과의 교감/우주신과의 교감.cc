#include <iostream>
#include <cmath>
#include <queue>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define SIZE 1000

using namespace std;

int unions[SIZE];
priority_queue<pair<double, int>> edges;
vector<pair<int, int>> points;

double distance(pair<int, int> &a, pair<int, int> &b) {
    return sqrt(pow(a.first-b.first, 2) + pow(a.second-b.second, 2));
}

int findRoot(int x) {
    while (unions[x] >= 0)
        x = unions[x];
    return x;
}

bool joinUnions(int a, int b) {
    a = findRoot(a);
    b = findRoot(b);

    if (a == b) return false;

    if (-unions[a] > -unions[b]) {
        unions[b] = a;
    }
    else {
        unions[b] = min(unions[b], unions[a]-1);
        unions[a] = b;
    }
    return true;
}

void solution() {
    int N, M, x, y, count;

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> x >> y;
        points.emplace_back(x, y);
        unions[i] = -1;
    }
    count = 0;
    for (int i = 0; i < M; ++i) {
        cin >> x >> y;
        if (joinUnions(x-1, y-1))
            count++;
    }

    for (int i = 0; i < N-1; ++i) {
        for (int j = i+1; j < N; ++j) {
            edges.emplace(-distance(points[i], points[j]), i*SIZE+j);
        }
    }


    int a, b;
    double dst;
    long double sum = 0.00;
    while (count < N-1) {
        do {
            a = edges.top().second / SIZE;
            b = edges.top().second % SIZE;
            dst = -edges.top().first;
            edges.pop();
        } while(!joinUnions(a, b));

        sum += dst;
        count++;
    }

    cout << fixed;
    cout.precision(2);
    cout << (sum+0.001);

}

int main() {
    fastIO();
    solution();

    return 0;
}