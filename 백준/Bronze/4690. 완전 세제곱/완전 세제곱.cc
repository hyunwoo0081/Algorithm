#include <iostream>
#define SIZE 100

using namespace std;

int main() {
    for (int a = 6; a <= SIZE; a++) {
        for (int b = 2; b < a; b++) {
            for (int c = b+1; c < a; c++) {
                for (int d = c+1; d < a; d++) {
                    if (a*a*a == b*b*b + c*c*c + d*d*d) {
                        cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ")\n";
                    }
                }
            }
        }
    }

    return 0;
}