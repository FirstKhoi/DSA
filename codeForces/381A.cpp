#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> cards(n);
    for (int i = 0; i < n; ++i) cin >> cards[i];

    int l = 0, r = n - 1;
    int sereja = 0, dima = 0;
    bool turn = true;

    while (l <= r) {
        int pick;
        if (cards[l] > cards[r]) {
            pick = cards[l++];
        } else {
            pick = cards[r--];
        }
        if (turn) sereja += pick;
        else dima += pick;
        turn = !turn;
    }
    cout << sereja << " " << dima << endl;
    return 0;
}