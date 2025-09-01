#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool binarySearch(vector<int> &a, int left, int right, int target) {
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(a[mid] == target) {
            return true;
        } else if(a[mid] > target) {
            right = mid - 1;
        } else left = mid + 1;
    }
    return false;
}

int main() {
    int t, n, m, count, cmp;
    vector<int> a;
    cin >> t;
    for(int k = 0; k < t; k++) {
        cin >> n >> m;
        a.resize(n);
        
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());
        count = 0;

        for(int i = 0; i < n; i++) {
            cmp = m - a[i];
            if(binarySearch(a, i + 1, n - 1, cmp)) {
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}