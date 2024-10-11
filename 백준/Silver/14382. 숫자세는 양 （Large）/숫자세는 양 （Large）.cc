#include <iostream>

using namespace std;

bool arr[10] = {false};

void select(long long N) {
    while (N > 0) {
        arr[N % 10] = true;
        N /= 10;
    }
}

bool isFinish() {
    for (auto c : arr)
        if (!c) return false;
    return true;
}

int main() {
    int T, N, i;
    
    cin >> T;
    for (int t = 1; t <= T; t++) {
        for (auto &c : arr)
            c = false;
        
        cin >> N;
        i = 1;
        while (N != 0 && i) {
            select((long long) i*N);
            
            if (isFinish()) break;
            i++;
        }
        
        cout << "Case #" << t << ": ";
        if (N == 0)
            cout << "INSOMNIA\n";
        else
            cout << i*N << '\n';
            
    }

    return 0;
}