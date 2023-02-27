#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> fruit;

void solution() {
    int N, L, a;

    cin >> N >> L;
    while (N--) {
        cin >> a;
        fruit.push_back(a);
    }
    sort(fruit.begin(), fruit.end());

    for (auto v : fruit)
        L += (v <= L);
    cout << L;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}