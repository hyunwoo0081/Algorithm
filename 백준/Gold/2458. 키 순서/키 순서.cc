#include <iostream>
#include <vector>
#define SIZE 500

using namespace std;

bool canVisit[SIZE][SIZE] = {false};
vector<int> edges[SIZE];
vector<int> revEdges[SIZE];


void visit(int base, int to, vector<int> edges[]) {
    canVisit[base][to] = true;
    
    for (auto next : edges[to]) {
        if (canVisit[base][next]) continue;
        visit(base, next, edges);
    }
}

int main() {
    int N, M, from, to;
    cin >> N >> M;
    
    for (int i = 0; i < M; i++) {
        cin >> from >> to;
        from--, to--;
        
        edges[from].push_back(to);
        revEdges[to].push_back(from);
    }
    
    for (int i = 0; i < N; i++) {
        visit(i, i, edges);
        visit(i, i, revEdges);
    }

    int result = 0;
    for (int i = 0; i < N; i++) {
        bool can = true;
        for (int j = 0; j < N; j++) {
            can &= canVisit[i][j];
        }
        
        result += can;
    }
    
    cout << result;
    
    return 0;
}