#include <iostream>

using namespace std;

typedef long long ll;

int xModK[15]; // x_i % k
int xDeg[15];
int tenModK[51]; // 10^n % k
ll counts[100][1<<15] = {0};
string x[15];

void calcCounts(int N, int K, int visited) {
    int nextVisit, f;
    for (int i = 0; i < K; i++)
        counts[i][visited] = 0;

    for (int i = 0; i < N; i++) {
        if (!(visited & (1<<i))) continue;

        nextVisit = visited ^ (1<<i);
        if (counts[0][nextVisit] < 0)
            calcCounts(N, K, nextVisit);

        for (int j = 0; j < K; j++) {
            f = (j*tenModK[xDeg[i]]+xModK[i]) % K;
            counts[f][visited] += counts[j][nextVisit];
        }
    }
}

ll gcd(ll a, ll b) {
    return b ? gcd(b, a%b) : a;
}

void solution() {
    int N, K;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> x[i];
    cin >> K;

    for (int i = 0; i < K; i++)
        for (int j = 1; j < (1<<N); j++)
            counts[i][j] = -1;

    for (int i = 0; i < N; i++) {
        xModK[i] = 0;
        xDeg[i] = x[i].length();
        for (auto c : x[i])
            xModK[i] = (xModK[i]*10 + (c-'0')) % K;

        for (int j = 0; j < K; j++)
            counts[j][1<<i] = 0;
        counts[xModK[i]][1<<i] = 1;
    }

    tenModK[0] = 1;
    for (int i = 1; i < 51; i++)
        tenModK[i] = (tenModK[i-1]*10) % K;

    if(N > 1)
        calcCounts(N, K, (1<<N)-1);
    ll count = counts[0][(1<<N)-1];

    if (count == 0)
        cout << "0/1";
    else {
        ll allCounts = 1;
        for (int i = N; i > 0; i--)
            allCounts *= i;
        ll r = gcd(allCounts, count);

        cout << count/r << '/' << allCounts/r;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}