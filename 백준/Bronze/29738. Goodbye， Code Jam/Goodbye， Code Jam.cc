#include <iostream>

using namespace std;

int main() {
    int T, N;
    
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N;
        if (N > 4500)
            cout << "Case #" << t << ": Round 1\n";
        else if (N > 1000)
            cout << "Case #" << t << ": Round 2\n";
        else if (N > 25)
            cout << "Case #" << t << ": Round 3\n";
        else
            cout << "Case #" << t << ": World Finals\n";
    }

    return 0;
}