#include <iostream>

using namespace std;

void solution() {
    int a, b, c, d, result;

    cin >> a >> b >> c >> d;
    
    result = a * b + c * d;
    result = max(result, a*c + b*d);
    result = max(result, a*d + c*b);
    
    cout << result;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}