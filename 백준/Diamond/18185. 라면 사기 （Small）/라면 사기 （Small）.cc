#include <iostream>
#define SIZE 100'005
#define INF 987654321

using namespace std;

int arr[SIZE]={0};

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, d;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    int result = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i+1] > arr[i+2]) {
            d = min(arr[i], arr[i+1] - arr[i+2]);
            result += 5*d;
            arr[i] -= d;
            arr[i+1] -= d;
        }
        
        for (int d = 3; d > 0; d--) {
            int cost = 2*d+1;
            int m = INF;
            for (int k = 0; k < d; k++) {
                m = min(m, arr[i+k]);
            }
            
            for (int k = 0; k < d; k++) {
                arr[i+k] -= m;
            }
            
            result += cost * m;
        }
    }
    
    cout << result;
    

    return 0;
}