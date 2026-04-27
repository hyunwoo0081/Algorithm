#include <iostream>
#define SIZE 1'000'005
#define INF 987654321

using namespace std;

int arr[SIZE]={0};

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, d, B, C;
    int costs[4]={0};
    long long result = 0;
    
    cin >> N >> B >> C;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    if (B <= C) {
        for (int i = 0; i < N; i++) {
            result += arr[i];
        }
        cout << result * B;
        return 0;
    }
    
    costs[1] = B;
    costs[2] = B+C;
    costs[3] = B+2*C;
    
    for (int i = 0; i < N; i++) {
        if (arr[i+1] > arr[i+2]) {
            d = min(arr[i], arr[i+1] - arr[i+2]);
            result += (long long) costs[2] * d;
            arr[i] -= d;
            arr[i+1] -= d;
        }
        
        for (int d = 3; d > 0; d--) {
            int cost = costs[d];
            int m = INF;
            for (int k = 0; k < d; k++) {
                m = min(m, arr[i+k]);
            }
            
            for (int k = 0; k < d; k++) {
                arr[i+k] -= m;
            }
            
            result += (long long) cost * m;
        }
    }
    
    cout << result;
    

    return 0;
}