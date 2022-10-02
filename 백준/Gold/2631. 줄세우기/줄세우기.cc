#include <iostream>
#include <vector>

using namespace std;

vector<int> stack;

int lower_bound(int num) {
    int lo, hi, mid;
    lo = 0, hi = stack.size();
    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (stack[mid] < num)
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo;
}

void solution() {
    int N, a;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a;
        if (stack.empty() || stack.back() < a)
            stack.push_back(a);
        else
            stack[lower_bound(a)] = a;
    }
    cout << N-stack.size();
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}