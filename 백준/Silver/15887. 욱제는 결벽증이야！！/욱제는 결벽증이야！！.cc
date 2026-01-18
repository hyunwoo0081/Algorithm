#include <iostream>
#include <vector>
#define SIZE 1000

using namespace std;

vector<pair<int, int>> q;
int arr[SIZE];
int main() {
    int N, tmp;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                tmp =  arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                
                q.emplace_back(j+1, j+2);
            }
        }
    }
    
    cout << q.size() << '\n';
    for (auto p : q) {
        cout << p.first << ' ' << p.second << '\n';
    }

    return 0;
}