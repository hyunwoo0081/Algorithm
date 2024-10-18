#include <iostream>

using namespace std;

int main() {
    long long N, R, m, e1, e2, result = 0;
    
    cin >> N >> R;
    for (m = 1; m*m <= (N-R); m++) {
        if ((N-R) % m == 0) {
            e1 = m;
            e2 = (N-R) / e1;
            
            if (N % e1 == R)
                result += e1;
            if (e1 != e2 && N % e2 == R)
                result += e2;
        }
    }
    cout << result;

    return 0;
}