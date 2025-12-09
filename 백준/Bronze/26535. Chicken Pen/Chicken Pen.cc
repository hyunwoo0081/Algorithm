#include <iostream>

using namespace std;

int main() {
    int N, k;
    
    cin >> N;
    
    k = 1;
    while(N > k*k) k++;
    
    for (int i = 0; i < k+2; i++) {
        for (int j = 0; j < k+2; j++) {
            if (i == 0 || i == k+1 || j == 0 || j == k+1)
                printf("x");
            else
                printf(".");
        }
        printf("\n");
    }

    return 0;
}