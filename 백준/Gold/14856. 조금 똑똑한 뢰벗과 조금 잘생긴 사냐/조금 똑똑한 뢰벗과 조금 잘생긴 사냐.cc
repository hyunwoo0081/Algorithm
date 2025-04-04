#include <iostream>
#include <algorithm>
#include <vector>
#define SIZE 1'000'000'000'000'000'000L
#define MAX 87

using namespace std;

long long fibo[MAX];

vector<long long> sums;

void solution() {
    long long a, b, c, cnt = 0, N;

    b = 0; c = 1;
    while (c <= SIZE) {
        a = b;
        b = c;
        c = a + b;
        fibo[cnt++] = c;
    }

    cin >> N;
    for (int i = MAX-1; i >= 0 && N > 0; i--) {
        if (fibo[i] <= N) {
            N -= fibo[i];
            sums.push_back(fibo[i]);
        }
    }
    reverse(sums.begin(), sums.end());

    cout << sums.size() << "\n";
    for (auto i : sums) {
        cout << i << " ";
    }
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}