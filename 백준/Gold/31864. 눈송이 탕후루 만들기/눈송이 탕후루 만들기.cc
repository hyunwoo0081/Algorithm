#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
#define SIZE 300000

using namespace std;

vector<tuple<int, int, int>> fruits;
vector<tuple<int, int, int>> sticks;

int gcdRecursive(int a, int b) {
    return b == 0 ? a : gcdRecursive(b, a%b);
}

int gcd(int a, int b) {
    if (a == 0 || b == 0)
        return max(1, max(abs(a), abs(b)));

    a = abs(a);
    b = abs(b);
    if (a < b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    return gcdRecursive(a, b);
}

bool compare(tuple<int,int,int> a, tuple<int,int,int> b) {
    return get<0>(a) < get<0>(b) ||
        get<0>(a) == get<0>(b) && get<1>(a) < get<1>(b) ||
        get<0>(a) == get<0>(b) && get<1>(a) == get<1>(b) && get<2>(a) < get<2>(b);
}

// x, y, 1(가장 작은 수) 찾아가는 걸 목표
int lowerBound(tuple<int, int, int> a, int N) {
    int left = 0;
    int right = N-1;
    int mid;

    while (left < right) {
        mid = (left + right) / 2;

        if (get<0>(fruits[mid]) < get<0>(a) ||
            get<0>(fruits[mid]) == get<0>(a) && get<1>(fruits[mid]) < get<1>(a)) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

// x, y, a.3 찾아가는 걸 목표
int upperBound(tuple<int, int, int> a, int N) {
    int left = 0;
    int right = N;
    int mid;

    while (left < right) {
        mid = (left + right) / 2;

        if (get<0>(fruits[mid]) < get<0>(a) ||
            get<0>(fruits[mid]) == get<0>(a) && get<1>(fruits[mid]) < get<1>(a) ||
            get<0>(fruits[mid]) == get<0>(a) && get<1>(fruits[mid]) == get<1>(a) && get<2>(fruits[mid]) <= get<2>(a)) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left-1;
}

void solution() {
    int N, M, x, y, g;

    cin >> N >> M;
    for (int n = 0; n < N; n++) {
        cin >> x >> y;

        g = gcd(x, y);
        fruits.emplace_back(x/g, y/g, g);
    }

    for (int m = 0; m < M; m++) {
        cin >> x >> y;

        g = gcd(x, y);
        sticks.emplace_back(x/g, y/g, g);
    }

    sort(fruits.begin(), fruits.end(), compare);

    // for (int n = 0; n < N; n++) {
    //     const auto f = fruits[n];
    //
    //     cout << get<0>(f) << ' ' << get<1>(f) << ' ' << get<2>(f) << '\n';
    // }

    int result = 0;
    for (auto s : sticks) {
        int lb = lowerBound(s, N);
        int ub = upperBound(s, N);
        int size = max(0, ub - lb + 1);

        result = max(result, size);

        // cout << get<0>(s) << ' ' << get<1>(s) << ' ' << get<2>(s) << ' ' << lb << ' ' << ub << ' ' << size << '\n';
    }

    cout << result;
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}