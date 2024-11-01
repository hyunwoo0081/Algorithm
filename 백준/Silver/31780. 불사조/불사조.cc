#include <iostream>

using namespace std;

void solution() {
    long long x, m;

    cin >> x >> m;
    cout << x * (m+1);
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}