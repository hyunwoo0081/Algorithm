#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define SIZE 10000

using namespace std;

bool isNotPrime[SIZE];
vector<ll> stack;

bool isPrime(ll N) {
    if (N < 2) return false;
    if (N < SIZE) return !isNotPrime[N];

    for (int i = 2; i*i <= N; i++) {
        if (!isNotPrime[i] && N % i == 0) return false;
    }
    return true;
}


void makePalindrome(ll from, ll to) {
    for (int i = 1; i < SIZE; i++) {
        ll num = i;
        ll palindrome = i;
        ll palindrome2 = i / 10;

        while (num > 0) {
            palindrome = palindrome * 10 + num % 10;
            palindrome2 = palindrome2 * 10 + num % 10;
            num /= 10;
        }

        if (isPrime(palindrome) && from <= palindrome && palindrome <= to) {
            stack.push_back(palindrome);
            // cout << palindrome << '\n';
        }
        if (isPrime(palindrome2) && from <= palindrome2 && palindrome2 <= to) {
            stack.push_back(palindrome2);
            // cout << palindrome2 << '\n';
        }
    }
    sort(stack.begin(), stack.end());
    // cout << '\n';
}

void solution() {
    ll a, b;

    cin >> a >> b;
    for (int i = 2; i*i < SIZE; i++) {
        if (isNotPrime[i]) continue;

        for (int j = i + i; j < SIZE; j += i) {
            isNotPrime[j] = true;
        }
    }

    makePalindrome(a, b);

    for (int i = 0; i < stack.size(); i++) {
        // if ((i == 0 || stack[i] != stack[i - 1]) && a <= stack[i] && stack[i] <= b)
            cout << stack[i] << '\n';
    }
    cout << -1;
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}