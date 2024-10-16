#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, bool> included; 
int main() {
    string s;
    int n;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        included[s] = true;
    }
    
    cout << n - included.size();

    return 0;
}