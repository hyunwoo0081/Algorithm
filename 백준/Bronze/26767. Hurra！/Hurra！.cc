// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;

int main() {
    long long N, n;
    
    cin >> N;
    for (n = 1; n <= N; n++) {
        if (n % 11 == 0 && n % 7 == 0)
            cout << "Wiwat!";
        else if (n % 11 == 0)
            cout << "Super!";
        else if (n % 7 == 0)
            cout << "Hurra!";
        else
            cout << n;
        cout << '\n';
    }

    return 0;
}