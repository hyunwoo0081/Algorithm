#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[100];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}

void solution() {
    int N, a, b;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int maxM = abs(arr[0] - arr[1]);
    for (int i = 2; i < N-1; i += 2) {
        a = maxM;
        b = abs(arr[i]-arr[i+1]);
        maxM = gcd(max(a, b), min(a, b));
    }
    if (N % 2 == 1) {
        a = maxM;
        b = abs(arr[N-1] - arr[N-2]);
        maxM = gcd(max(a, b), min(a, b));
    }

    vector<int> result;
    for (int i = 2; i*i <= maxM; i++) {
        if (maxM % i == 0) {
            result.push_back(i);
            if (i*i != maxM)
                result.push_back(maxM/i);
        }
    }
    result.push_back(maxM);

    sort(result.begin(), result.end());
    for (auto r:result)
        cout << r << ' ';

}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}