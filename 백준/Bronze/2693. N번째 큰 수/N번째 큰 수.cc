#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

int arr[1000];
int arrSize = 0;

void split(string &s) {
    istringstream ss(s); // ss << "string";
    string num;
    arrSize = 0;

    while (getline(ss, num, ' '))
        arr[arrSize++] = (stoi(num));
}

void solution() {
    int n;
    string s;

    cin >> n;
    cin.ignore();
    while (n--) {
        getline(cin, s);
        split(s);
        sort(arr, arr+arrSize);
        cout << arr[7] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}