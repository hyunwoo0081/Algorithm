#include <iostream>
#define SIZE 32

using namespace std;

int cnts[SIZE] = {0};

int main() {
    int N, s, e, B;
    
    cin >> N;
    while (N--) {
        cin >> s >> e;
        for (; s < e; s++)
            cnts[s]++;
    }
    cin >> B;
    
    N = 0;
    for (int i = 0; i < SIZE; i++)
        N = max(N, cnts[i]);
    
    cout << (B >= N);

    return 0;
}