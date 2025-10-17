// Online C++ compiler to run C++ program online
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> inHome;
vector<string> isShown;
vector<string> inHomeNotShown;
int contain(vector<string> &v, string s) {
    return find(v.begin(), v.end(), s) != v.end();
}

int main() {
    int N, M;
    string s;
    
    getline(cin, s);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s;
        inHome.push_back(s);
    }
    
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> s;
        isShown.push_back(s);
    }
    
    for (auto v : inHome) {
        if (!contain(isShown, v)) {
            inHomeNotShown.push_back(v);
        }
    }
    if (!contain(isShown, "swi")) {
        inHomeNotShown.push_back("swi");
    }
    
    
    // 1 dongho
    if (contain(inHome, "dongho")) {
        cout << "dongho";
        return 0;
    }
    
    // 2 only one person, inHomeNotShown has unique value
    if (inHomeNotShown.size() == 1) {
        cout << inHomeNotShown[0];
        return 0;
    }
    
    // 3 bumin
    if (contain(inHomeNotShown, "bumin")) {
        cout << "bumin";
        return 0;
    }
    
    // 4 cake
    if (contain(inHomeNotShown, "cake")) {
        cout << "cake";
        return 0;
    }
    
    // 5 lawyer
    if (contain(inHomeNotShown, "lawyer")) {
        cout << "lawyer";
        return 0;
    }
    
    // 6
    sort(inHomeNotShown.begin(), inHomeNotShown.end());
    if (inHomeNotShown[0] == "swi") {
        cout << inHomeNotShown[1];
    }
    else {
        cout << inHomeNotShown[0];
    }
    

    return 0;
}