#include <iostream>
#include <set>
#include <climits>
using namespace std;

int main() {
    int n;
    set<long long> prices;
    set<long long>::iterator it;
    long long sellPrices, minimumloss = LLONG_MAX;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> sellPrices;
        it = prices.upper_bound(sellPrices);
        if(it != prices.end()) {
            long long loss = *it - sellPrices;
            minimumloss = min(loss, minimumloss);
        }
        prices.insert(sellPrices);
    }
    cout << minimumloss;
    return 0;
}