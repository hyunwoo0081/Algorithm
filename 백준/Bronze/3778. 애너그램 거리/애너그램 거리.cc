#include <iostream>
#define SIZE 26

using namespace std;

int cnt1[SIZE], cnt2[SIZE];

int abs(int a) {
    return a > 0 ? a : -a;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
    int N;
    string s1, s2;
    
    cin >> N;
    cin.ignore();
    for (int t = 1; t <= N; t++) {
        getline(cin, s1);
        getline(cin, s2);
        
        for (int i = 0; i < SIZE; i++) {
            cnt1[i] = cnt2[i] = 0;
        }
        
        for (auto c : s1) cnt1[c-'a']++;
        for (auto c : s2) cnt2[c-'a']++;
        
        int diff = 0;
        for (int i = 0; i < SIZE; i++) {
            diff += abs(cnt1[i] - cnt2[i]);
        }
        
        cout << "Case #" << t << ": " << diff << '\n';
    }

    return 0;
}