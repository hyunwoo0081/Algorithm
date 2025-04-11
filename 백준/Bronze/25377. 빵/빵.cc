#include <iostream>

using namespace std;

int main() {
    int N, A, B, result = -1;
    
    cin >> N;
    while (N--) {
        cin >> A >> B;
        
        if (A <= B && (result == -1 || result > B)) {
            result = B;
        }
    }
    cout << result;

    return 0;
}