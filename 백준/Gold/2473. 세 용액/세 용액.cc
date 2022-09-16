#include <iostream>
#include <algorithm>

using namespace std;

int feat[5000];

void solution() {
    int N;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> feat[i];

    sort(feat, feat+N);

    int i, j;
    long long a, b, c, absMin;
    absMin = (1LL<<62);
    for (int k = 0; k < N-1; k++) {
        i = k+1, j = N-1;
        while (i < j) {
            if (abs((long long)feat[k] + feat[i] + feat[j]) < absMin)
                a = feat[k], b = feat[i], c = feat[j], absMin = abs(a+b+c);

            if (feat[i] + feat[j] < -feat[k])
                i++;
            else
                j--;
        }
    }

    cout << a << ' ' << b << ' ' << c << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}