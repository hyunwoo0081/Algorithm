#include <iostream>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int addressArr[4];

void printAddress(int address) {
    int mask = 255;
    for (int i = 3; i >= 0; --i) {
        addressArr[i] = address & mask;
        address = address >> 8;
    }

    for (int i = 0; i < 3; ++i) {
        cout << addressArr[i] << '.';
    }
    cout << addressArr[3] << '\n';
}

int getIntAddress(string &address) {
    int result = 0;
    int num = 0;
    for (char c : address) {
        if (c == '.') {
            result += num;
            result <<= 8;
            num = 0;
            continue;
        }
        num = num*10 + c-'0';
    }
    result += num;

    return result;
}

void solution() {
    int n, m, minAddress, maxAddress;
    string address;

    cin >> n;

    cin >> address;
    int ad = getIntAddress(address);
    minAddress = maxAddress = ad;

    for (int i = 1; i < n; ++i) {
        cin >> address;
        ad = getIntAddress(address);
        minAddress = min(minAddress, ad);
        maxAddress = max(maxAddress, ad);
    }

    int netMask = ~0;
    for (m = 0; m < 32; ++m) {
        if ((minAddress & netMask) == (maxAddress & netMask)) {
            break;
        }
        netMask <<= 1;
    }

    printAddress(minAddress & netMask);
    printAddress(netMask);
}

int main() {
    fastIO();
    solution();

    return 0;
}