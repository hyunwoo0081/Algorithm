#include <iostream>

using namespace std;

void solution() {
    int N;

    cin >> N;
    cout << (N == 2 ? 3 : N);
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}