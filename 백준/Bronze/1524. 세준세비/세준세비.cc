#include <iostream>
#include <algorithm>
#define SIZE 1'000'000

using namespace std;

int srr[SIZE], brr[SIZE];

int main() {
    int T, N, M, i, s, b;
    
    cin >> T;
    while (T-- ) {
        cin >> N >> M;
        for (i = 0; i < N; i++)
            cin >> srr[i];
            
        for (i = 0; i < M; i++)
            cin >> brr[i];
            
        sort(srr, srr+N);
        sort(brr, brr+M);
        
        s = b = 0;
        while (s < N && b < M) {
            if (srr[s] < brr[b]) s++;
            else b++;
        }
        
        cout << (s == N ? 'B' : 'S') << '\n';
    }

    return 0;
}