#include <iostream>
#define SIZE 100

using namespace std;

int Ts[SIZE];
int main() {
    int N, X, i;
    
    cin >> N >> X;
    for (i = 0; i < N; i++)
        cin >> Ts[i];
        
    i = 0;
    while (Ts[i%N] >= X) {
        i++;
        X++;
    }
    cout << i%N + 1;

    return 0;
}