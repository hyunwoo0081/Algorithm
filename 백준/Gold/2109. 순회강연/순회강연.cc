#include <iostream>
#include <queue>
#include <algorithm>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

priority_queue<pair<int, int>> sorted;
int maxPrice[10001] = {0};

void solution() {
   int n, d, p;

   cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p >> d;
        sorted.emplace(p, d);
    }

    int count = 0, sum = 0;
    while (count < n && !sorted.empty()) {
        p = sorted.top().first;
        d = sorted.top().second;
        sorted.pop();
        sum += p;
        while (d > 0 && maxPrice[d] != 0) {
            if (maxPrice[d] < p) {
                int tmp = p;
                p = maxPrice[d];
                maxPrice[d] = tmp;
            }
            d--;
        }

        if (d > 0) {
            maxPrice[d] = p;
            count++;
        }
        else {
            sum -= p;
        }
    }

    cout << sum;
}


int main() {
    fastIO();
    solution();

    return 0;
}