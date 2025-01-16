#include <iostream>

using namespace std;

long long stacks[20];
int stackSize = 0;
void solution() {
    int n, m, k;

    cin >> n >> m >> k;
    cout << k * m + m;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}