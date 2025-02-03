#include <iostream>

using namespace std;

int arr[] = {13, 7, 5, 3, 3, 2};

int main() {
    int c;
    double r1, r2;
    
    r1 = 0;
    for (auto a : arr) {
        cin >> c;
        r1 += c * a;
    }
    
    r2 = 1.5;
    for (auto a : arr) {
        cin >> c;
        r2 += c * a;
    }
    
    cout << (r1 <= r2 ? "ekwoo" : "cocjr0208");

    return 0;
}