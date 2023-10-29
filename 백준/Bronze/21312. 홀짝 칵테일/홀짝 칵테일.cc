#include <iostream>

using namespace std;

void solution() {
    long long arr[3], mul=1;
    bool hasOdd = false;

    for (auto &a : arr) {
        cin >> a;
        if (a % 2) {
            hasOdd = true;
            mul *= a;
        }
    }

    cout << (hasOdd ? mul : arr[0] * arr[1] * arr[2]);
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}