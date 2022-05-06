#include <iostream>
#include <algorithm>
#include <queue>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define SIZE 100000

using namespace std;

struct Position {
    int x, y, z, index;
    Position(int x, int y, int z, int index) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->index = index;
    }
};

int unions[SIZE];
priority_queue<pair<int, pair<int, int>>> edges;
vector<Position> points;

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

bool orderedX(Position &a, Position &b) {
    return a.x <= b.x;
}

bool orderedY(Position &a, Position &b) {
    return a.y <= b.y;
}

bool orderedZ(Position &a, Position &b) {
    return a.z <= b.z;
}

void solution() {
    int N, x, y, z;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> x >> y >> z;
        points.emplace_back(x, y, z, i);
        unions[i] = -1;
    }

    sort(points.begin(), points.end(), orderedX);
    for (int i = 1; i < N; ++i)
        edges.emplace(-abs(points[i].x - points[i-1].x), make_pair(points[i].index, points[i-1].index));

    sort(points.begin(), points.end(), orderedY);
    for (int i = 1; i < N; ++i)
        edges.emplace(-abs(points[i].y - points[i-1].y), make_pair(points[i].index, points[i-1].index));

    sort(points.begin(), points.end(), orderedZ);
    for (int i = 1; i < N; ++i)
        edges.emplace(-abs(points[i].z - points[i-1].z), make_pair(points[i].index, points[i-1].index));


    int count = 0;
    int a, b, dist;
    long long sum = 0;
    while (count < N-1) {
        do {
            a = edges.top().second.first;
            b = edges.top().second.second;
            dist = -edges.top().first;
            edges.pop();
        } while (!joinUnions(a, b));

        sum += dist;
        count++;
    }

    cout << sum;
}

int main() {
    fastIO();
    solution();

    return 0;
}