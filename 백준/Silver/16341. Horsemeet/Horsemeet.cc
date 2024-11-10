#include <iostream>

using namespace std;

int main() {
    int A, B, C, D;
    
    cin >> A >> B >> C >> D;
    
    if ((A+B)%2 == (C+D)%2)
        cout << "black";
    else
        cout << "white";

    return 0;
}