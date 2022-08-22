#include <iostream>

using namespace std;

void solution() {
    cout << "SHIP NAME      CLASS          DEPLOYMENT IN SERVICE\n"
            "N2 Bomber      Heavy Fighter  Limited    21        \n"
            "J-Type 327     Light Combat   Unlimited  1         \n"
            "NX Cruiser     Medium Fighter Limited    18        \n"
            "N1 Starfighter Medium Fighter Unlimited  25        \n"
            "Royal Cruiser  Light Combat   Limited    4         ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}