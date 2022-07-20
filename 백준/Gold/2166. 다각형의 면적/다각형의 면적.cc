#include <iostream>

using namespace std;

typedef long long ll;

ll vectorProduct(ll x1, ll y1, ll x2, ll y2) {
    return x1*y2 - x2*y1;
}

void solution() {
    int N, x1, y1, x2, y2, x3, y3;
    long long area = 0;

    cin >> N >> x1 >> y1;
    x2 = x1, y2 = y1;
    N--;
    while (N--) {
        cin >> x3 >> y3;
        area += vectorProduct(x2, y2, x3, y3);
        x2 = x3, y2 = y3;
    }
    area += vectorProduct(x2, y2, x1, y1);

    cout << abs(area)/2 << (area%2 ? ".5" : ".0");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}