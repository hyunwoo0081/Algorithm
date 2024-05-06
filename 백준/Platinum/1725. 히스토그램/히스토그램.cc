#include <iostream>
#include <vector>
#include <stack>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

vector<int> h;
stack<int> s;

void solution() {
    int N, x, maxArea;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> x;
        h.push_back(x);
    }
    h.push_back(0);

    maxArea = 0;
    for (int i = 0; i < h.size(); ++i) {
        while (!s.empty() && h[s.top()] >= h[i]) {
            int midH = h[s.top()];
            s.pop();
            int width = -1;

            if (s.empty())
                width = i;
            else
                width = (i - s.top() - 1);
            maxArea = max(maxArea, midH*width);
        }
        s.push(i);
    }

    cout << maxArea;
}

int main() {
    fastIO();
    solution();

    return 0;
}