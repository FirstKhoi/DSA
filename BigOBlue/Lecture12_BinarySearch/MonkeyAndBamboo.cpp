#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 100005
using namespace std;

int a[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t++) {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        a[0] = 0; 
        int l = 1, r = 0;
        for(int i = 1; i <= n; i++) {
            r = max(r, a[i] - a[i - 1]);
        }
        r += 100;
    
        int res = r;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            int k = mid;
            bool ok = true;
            for(int i = 1; i <= n; i++) {
                int diff = a[i] - a[i - 1];
                if(diff > k) {
                    ok = false;
                    break;
                }
                if(diff == k) k--;
            }
            if(ok) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << "Case " << t << ": " << res << endl;
    }
    return 0;
}