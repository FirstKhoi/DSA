#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int Q;
    cin >> Q;
    set<ll> heap;
    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            ll v;
            cin >> v;
            heap.insert(v);
        } else if (type == 2) {
            ll v;
            cin >> v;
            heap.erase(v);
        } else if (type == 3) {
            cout << *heap.begin() << '\n';
        }
    }
    return 0;
}