#include <iostream>
#define SIZE 10000

using namespace std;

bool maps[SIZE] = {false};

int main() {
    int M, N, a, b;
    
    cin >> M >> N;
    while (N--) {
        cin >> a >> b;
        a--, b--;
        for (; a <= b; a++)
            maps[a] = true;
    }
    
    bool isFull = true;
    for (int i = 0; i < M; i++)
        isFull &= maps[i];
    cout << (isFull ? "YES" : "NO");

    return 0;
}