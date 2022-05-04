#include <iostream>
#include <vector>
#include <cmath>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define dist(a, b) sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second))

using namespace std;

bool visited[100] = {false};
vector<pair<double, double>> points;

void solution() {
    int n, point, edgeCount;
    double x, y, sum;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        points.emplace_back(x, y);
    }

    point = 0;
    edgeCount = 0;
    sum = 0;
    while (edgeCount < n-1) {
        int minIndex = -1;
        double minDist = -1, distance;

        visited[point] = true;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) continue;
            for (int j = 0; j < n; ++j) {
                if (!visited[j]) {
                    distance = dist(points[j], points[i]);
                    if (minIndex == -1 || distance < minDist) {
                        minIndex = j;
                        minDist = distance;
                    }
                }
            }
        }

        sum += minDist;
        point = minIndex;
        edgeCount++;
    }

    cout << sum;
}

int main() {
    fastIO();
    solution();

    return 0;
}