#include <iostream>

using namespace std;

int main() {
    int prefix[11] = {0};

    for (int i = 1; i <= 10; i++) {
        cin >> prefix[i];
        prefix[i] += prefix[i-1];
    }

    int i = 0, j = 10, target = 987654321, f;
    while (i < j) {
        f = prefix[j]-prefix[i];
        if (abs(f-100) < abs(target-100) ||
            abs(f-100) == abs(target-100) && f > target)
            target = f;

        if (f > 100)
            j--;
        else
            i++;
    }
    cout << target;

    return 0;
}
