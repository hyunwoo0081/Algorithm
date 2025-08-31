#include <iostream>

using namespace std;

int main() {
    string a,b;
    
    cin >> a >> b;
    for (auto c : b) {
        bool has = false;
        for (auto ca : a) has |= c==ca;
        
        if (!has) cout << c;
    }

    return 0;
}