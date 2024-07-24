#include <iostream>

using namespace std;

int main() {
    int T, A, B, C, sum;
    
    cin >> T;
    while (T--) {
        cin >> A >> B >> C;
        
        sum = A*15 + B*20 + C*25;
        
        if (9000 - sum > 40*100) {
            cout << "impossible\n";
        }
        else {
            cout << (9000 - sum)/40 + ((9000-sum) % 40 != 0) << '\n';
        }
    }

    return 0;
}