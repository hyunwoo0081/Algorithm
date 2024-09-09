// Online C++ compiler to run C++ program online
#include <iostream>
#define SIZE 15000

using namespace std;

bool selected[SIZE] = {false};

int main() {
    int N, a, cnt;
    
    cin >> N;
    while (N--) {
        cin >> a;
        selected[a-1] = true;
    }
    
    cnt = 0;
    for (auto b : selected)
        cnt += b;
    
    cout << SIZE - cnt;

    return 0;
}