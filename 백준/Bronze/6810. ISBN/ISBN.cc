#include <iostream>
#include <queue>
#define SIZE 20

using namespace std;

bool maps[SIZE][SIZE];
int visited[SIZE][SIZE];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

queue<pair<int, int>> q;

void solution() {
    long long n = 9780921418L;
    int a, r, result = 0;

    r = 3;
    while (n > 0) {
        result += (n % 10L) * r;
        n /= 10;
        r = (r == 3 ? 1 : 3);
    }

    r = 1;
    for (int i = 0; i < 3; i++) {
        cin >> a;
        result += a * r;
        r = (r == 3 ? 1 : 3);
    }

    cout << "The 1-3-sum is " << result;
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}