#include <iostream>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void solution() {
    int start, end;
    cin >> start >> end;

    int sum = 0, count = 0;
    for (int i = 1; i < 1000; ++i) {
        for (int j = 0; j < i; ++j) {
            count++;
            if (start <= count) {
                sum += i;
                if (count == end) {
                    cout << sum;
                    return;
                }
            }
        }
    }
}

int main() {
    fastIO();
    solution();

    return 0;
}