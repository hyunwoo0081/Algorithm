#include <iostream>
#define SIZE 50

using namespace std;

int cnts[SIZE] = {1, 0};
int main() {
    int N, M, L, i, cnt;
    
    i = cnt = 0;
    cin >> N >> M >> L;
    while (cnts[i] < M) {
        cnt++;
        if (cnts[i] % 2)
            i = (i + L) % N;
        else
            i = (i - L + N) % N;
        
        cnts[i]++;
    }
    cout << cnt;

    return 0;
}