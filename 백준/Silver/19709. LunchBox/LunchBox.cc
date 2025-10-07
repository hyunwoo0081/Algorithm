#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr;
int main() {
    int N, M, a, result;
    
    cin >> N >> M;
    while (M--) {
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    
    result = 0;
    for (auto c : arr) {
        if (c <= N) {
            N -= c;
            result++;
        }
    }
    
    cout << result;
    
    return 0;
}