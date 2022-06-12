#include <iostream>
#include <vector>

using namespace std;

vector<int> times;

long long getCount(long long s) {
    long long count = 0;
    for (auto t: times) {
        count += s / t;
    }
    return count;
}

long long binarySearch(int M, long long maxTk) {
    long long start, end, mid, fx;
    start = 0;
    end = maxTk*M;
    while (start < end) {
        mid = start+(end-start)/2;
        fx = getCount(mid);
        if (M > fx) {
            start = mid+1;
        }
        else {
            end = mid;
        }
    }

    return end;
}

void solution() {
    int N, M, Tk, maxTk = 0;

    cin >> N >> M;
    while (N--) {
        cin >> Tk;
        maxTk = max(maxTk, Tk);
        times.push_back(Tk);
    }

    cout << binarySearch(M, maxTk);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}