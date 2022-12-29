#include <iostream>
#include <vector>
#include <algorithm>
#define SIZE 100'000

using namespace std;

vector<pair<int, int>> lines;
vector<int> stack;
int prevIndex[SIZE];

int lowerBound(int index) {
    int lo = 0, mid, hi = stack.size()-1;
    int target = lines[index].second;

    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (target < lines[stack[mid]].second)
            hi = mid;
        else if (lines[stack[mid]].second < target)
            lo = mid + 1;
        else
            return mid;
    }

    return lo;
}

void solution() {
    int N, a, b;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        lines.emplace_back(a, b);
        prevIndex[i] = -1;
    }
    sort(lines.begin(), lines.end());
    

    for (int i = 0; i < N; i++) {
        if (stack.empty() || lines[stack.back()].second < lines[i].second) {
            if (!stack.empty())
                prevIndex[i] = stack.back();
            stack.push_back(i);
        }
        else {
            b = lowerBound(i);
            if (b > 0)
                prevIndex[i] = stack[b-1];
            stack[b] = i;
        }
    }
    cout << N - stack.size() << '\n';

    b = stack.back();
    stack.clear();

    stack.push_back(b);
    while (prevIndex[stack.back()] >= 0)
        stack.push_back(prevIndex[stack.back()]);

    for (int i = 0; i < N; i++) {
        if (!stack.empty() && stack.back() == i) {
            stack.pop_back();
            continue;
        }
        cout << lines[i].first << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}