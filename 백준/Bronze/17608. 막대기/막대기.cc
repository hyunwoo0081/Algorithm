#include <iostream>
#include <vector>

using namespace std;

vector<int> s;
int main() {
    int N, a;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a;
        while (!s.empty() && s.back() <= a) {
            s.pop_back();
        }
        
        s.push_back(a);
    }
    
    std::cout << s.size();

    return 0;
}