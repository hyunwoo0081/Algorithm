#include <iostream>

using namespace std;

void solution() {
    double p1, p2, a;
    int N;

    p1 = p2 = 987654321987654;
    cin >> N;
    while (N--) {
        cin >> a;

        p2 = min(p2, a);
        if (p2 < p1) {
            a = p1;
            p1 = p2;
            p2 = a;
        }
    }

    cout.precision(2);
    cout << fixed << p2;
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}