#include <iostream>

using namespace std;

int main() {
    int w, h, r;
    cin >> w >> h >> r;
    cout << w*h-r*r*3.141592/4.;

    return 0;
}