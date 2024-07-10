#include <iostream>
#define max(a, b) ((a) > (b)) ? (a) : (b)

using namespace std;

int main() {
    long long N, Th, a, prefixSum = 0, count = 0;
    
    cin >> N >> Th;
    while (N--) {
        cin >> a;
        
        prefixSum = max(0, prefixSum + a);
        count += prefixSum >= Th;
    }
    
    cout << count;

    return 0;
}