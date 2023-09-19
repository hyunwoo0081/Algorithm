#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> burgers;
vector<int> sides;
vector<int> drinks;

void solution() {
    int b, s, d, setCount, cost, all;

    cin >> b >> s >> d;
    setCount = min(min(b, s), d);
    for (int i = 0; i < b; i++) {
        cin >> cost;
        burgers.push_back(cost);
    }
    for (int i = 0; i < s; i++) {
        cin >> cost;
        sides.push_back(cost);
    }
    for (int i = 0; i < d; i++) {
        cin >> cost;
        drinks.push_back(cost);
    }
    sort(burgers.begin(), burgers.end(), greater<>());
    sort(sides.begin(), sides.end(), greater<>());
    sort(drinks.begin(), drinks.end(), greater<>());

    cost = 0;
    for (int i = 0; i < setCount; i++)
        cost += burgers[i] + sides[i] + drinks[i];
    all = cost;
    cost = cost / 10 * 9;

    for (int i = setCount; i < b; i++) {
        all += burgers[i];
        cost += burgers[i];
    }
    for (int i = setCount; i < s; i++) {
        all += sides[i];
        cost += sides[i];
    }
    for (int i = setCount; i < d; i++) {
        all += drinks[i];
        cost += drinks[i];
    }

    cout << all << '\n' << cost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}