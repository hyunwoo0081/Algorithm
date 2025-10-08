#include <iostream>
#include <algorithm>
#include <vector>
#define SIZE 500

using namespace std;

// [0]: S, [1]: I
int cnts[SIZE][2];
vector<int> cars[SIZE];

int main() {
    int T, N, C, L, loc, seats, remains, getIn;
    char al;
    
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N >> C >> L;
        
        for (int l = 0; l < L; l++) {
            cnts[l][0] = cnts[l][1] = 0;
            cars[l].clear();
        }
        
        for (int i = 0; i < N; i++) {
            cin >> loc >> al;
            cnts[loc-1][al=='I']++;
        }
        
        for (int i = 0; i < C; i++) {
            cin >> loc >> seats;
            cars[loc-1].push_back(seats);
        }
        
        for (int l = 0; l < L; l++) {
            sort(cars[l].begin(), cars[l].end());
            
            while (!cars[l].empty() && cnts[l][0] > 0) {
                seats = cars[l].back();
                cars[l].pop_back();
                
                cnts[l][0]--;
                seats -= 1;
                
                getIn = min(seats, cnts[l][1]);
                cnts[l][1] -= getIn;
                seats -= getIn;
                
                getIn = min(seats, cnts[l][0]);
                cnts[l][0] -= getIn;
                seats -= getIn;
            }
        }
        
        
        remains = 0;
        for (int l = 0; l < L; l++) {
            remains += cnts[l][0] + cnts[l][1];
            cars[l].clear();
        }
        
        cout << "Data Set " << t << ":\n" << remains << '\n';
    }
    
    return 0;
}