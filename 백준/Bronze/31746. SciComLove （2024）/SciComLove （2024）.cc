#include <iostream>

using namespace std;

int main() {
    int n;
    string a = "SciComLove";
    string b = "evoLmoCicS";
    
    cin >> n;
    cout << (n % 2 ? b : a);
    return 0;
}