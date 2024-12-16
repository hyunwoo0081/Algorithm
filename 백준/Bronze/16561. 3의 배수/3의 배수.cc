#include <iostream>

using namespace std;

void solution() {
    int N, cnt;
    cin >> N;

    N /= 3;
    cnt = 0;
    for (int a = 1; a <= N-2; a++) {
        // for (int b = 1; b <= N-a-1; b++) {
        //     int c = N - a - b;
        //     cnt ++;
        // }
        cnt += (N-a)-1;
    }
    cout << cnt;
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}