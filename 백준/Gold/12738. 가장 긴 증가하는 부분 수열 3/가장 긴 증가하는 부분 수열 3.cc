#include <iostream>
#include <vector>

using namespace std;

vector<int> stack;

int lower_bound(int x) {
    int lo = 0, hi = stack.size()-1, mid;
    while (lo < hi) {
        mid = (lo + hi + 1) / 2;
        if (x <= stack[mid])
            hi = mid - 1;
        else
            lo = mid;
    }
    return x <= stack[hi] ? hi : hi+1;
}

void solution() {
    int N, x;

    cin >> N;
    while (N--) {
        cin >> x;

        if (stack.empty() || stack.back() < x)
            stack.push_back(x);
        else
            stack[lower_bound(x)] = x;
    }

    cout << stack.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}