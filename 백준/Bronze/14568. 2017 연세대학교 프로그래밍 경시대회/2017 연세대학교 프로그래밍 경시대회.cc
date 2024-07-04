#include <iostream>

using namespace std;

int main() {
    int N, count = 0;;
    
    cin >> N;
    for (int a = 1; a < N-3; a++) {
        for (int b = a+2; b < N-a; b++) {
            count += N-a-b > 0 && (N-a-b)%2 == 0;
        }
    }
    cout << count;

    return 0;
}