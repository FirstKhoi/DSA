    #include<iostream>
    #include<algorithm>
    #include<vector>
    using namespace std;

    int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        int n; cin >> n;
        vector<int> height(n);
        for(int i = 0; i < n; i++) {
            cin >> height[i];
        }

        int Q; cin >> Q;
        vector<int> queries(Q);
        for(int i = 0; i < Q; i++) {
            cin >> queries[i];
        }

        for(int i = 0; i < Q; i++) {
            int h = queries[i];
            auto it1 = lower_bound(height.begin(), height.end(), h);
            if(it1 == height.begin()) {
                cout << "X ";
            }
            else {
                it1--;
                cout << *it1 << " ";
            }
            auto it2 = upper_bound(height.begin(), height.end(), h);
            if(it2 == height.end()) {
                cout << 'X';
            } else {
                cout << *it2;
            }
            cout << endl;
        }
        return 0;
    }