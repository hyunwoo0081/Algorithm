#include <iostream>
#include <unordered_map>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

unordered_map<int, bool> setA;

void solution() {
    int Na, Nb, x, count;

    cin >> Na >> Nb;
    count = Na + Nb;
    while (Na--) {
        cin >> x;
        setA[x] = true;
    }

    while (Nb--) {
        cin >> x;
        count -= 2*setA[x];
    }
    cout << count;
}

int main() {
    fastIO();
    solution();

    return 0;
}