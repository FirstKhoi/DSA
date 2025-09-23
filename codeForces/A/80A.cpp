#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    int next = n + 1;
    while (!isPrime(next)) next++;

    if (next == m)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
