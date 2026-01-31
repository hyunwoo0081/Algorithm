#include <iostream>
#define ll long long

using namespace std;

ll gcd(ll a, ll b) {
    return b > 0 ? gcd(b, a%b) : a;
} 

int main() {
    long long a, b;
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> a >> b;
    cout << a * b / gcd(a, b);

    return 0;
}