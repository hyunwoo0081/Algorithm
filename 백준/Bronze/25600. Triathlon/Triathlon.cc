#include <iostream>

using namespace std;

int main() {
    long long N, a, d, g, result = 0, score;
    
    cin >> N;
    while (N--) {
        cin >> a >> d >> g;
        
        score = (a == d+g ? 2 : 1) * a * (d+g);
        result = result > score ? result : score;
    }
    cout << result;

    return 0;
}