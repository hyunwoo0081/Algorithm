#include <iostream>

using namespace std;

int main() {
    int N;
    
    cin >> N;
    
    cout << N << " in Ottawa\n";
    cout << (N+2100)%2400 << " in Victoria\n";
    cout << (N+2200)%2400 << " in Edmonton\n";
    cout << (N+2300)%2400 << " in Winnipeg\n";
    cout << N << " in Toronto\n";
    cout << (N+100)%2400 << " in Halifax\n";
    cout << (N/100+(N%100+30)/60+1)%24*100 +(N%100+30)%60 << " in St. John's\n";

    return 0;
}