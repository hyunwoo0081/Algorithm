#include <iostream>
#include <vector>
#define SIZE 10

using namespace std;

int dp[1 << SIZE];
bool canVisits[1 << SIZE];
int persons[SIZE];
vector<int> edges[SIZE];

int getCanVisit(int group, int visited, int from) {
    int result = visited;
    if (visited == group) {
        return group;
    }
    
    for (int e : edges[from]) {
        if ((group & (1 << e)) == 0) continue;
        if ((visited & (1 << e)) != 0) continue;
        
        result |= getCanVisit(group, result | (1 << e), e);
    }
    
    return result;
}

int main() {
    int N, M, e;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> persons[i];
    }
    
    for (int i = 0; i < N; i++) {
        cin >> M;
        while (M--) {
            cin >> e;
            edges[i].push_back(e-1);
        }
    }
    
    // except select all, select nothing
    // make canVisit
    for (int groups = 1; groups < (1 << N)-1; groups++) {
        for (e = 0; e < N; e++) {
            if ((groups & (1 << e)) != 0) break;
        }
        
        canVisits[groups] = groups == getCanVisit(groups, (1 << e), e);
    }
    
    int result = -1;
    // get all posible groups
    for (int groups = 1; groups < (1 << N)-1; groups++) {
        // 
        if (!canVisits[groups] || !canVisits[((1<<N)-1) & (~groups)]) continue;
        
        int f;
        int part0 = 0;
        int part1 = 0;
        for (int e = 0; e < N; e++) {
            if ((groups & (1 << e)) == 0) {
                part0 += persons[e];
            }
            else {
                part1 += persons[e];
            }
        }
        
        f = abs(part1 - part0);
        if (result == -1 || result > f) {
            result = f;
        }
        // cout << groups << ' ' << f << '\n';
    }
    
    cout << result;

    return 0;
}