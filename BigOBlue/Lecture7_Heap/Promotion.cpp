#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k, x, nbills = 0;
    long long money = 0;
    vector<bool> taken(MAX, false);
    
    auto maxHeapCmp = [](const pair<int,int>& a, const pair<int,int>& b) { return a.second < b.second; };
    auto minHeapCmp = [](const pair<int,int>& a, const pair<int,int>& b) { return a.second > b.second; };
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(maxHeapCmp)> maxHeap(maxHeapCmp);
    priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(minHeapCmp)> minHeap(minHeapCmp);
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> k;

        for (int j = 0; j < k; j++) {
            cin >> x;
            maxHeap.push({++nbills, x});
            minHeap.push({nbills, x});
        }

        while (!maxHeap.empty() && taken[maxHeap.top().first]) {
            maxHeap.pop();
        }

        while (!minHeap.empty() && taken[minHeap.top().first]) {
            minHeap.pop();
        }

        money += maxHeap.top().second - minHeap.top().second;
        taken[maxHeap.top().first] = taken[minHeap.top().first] = true;
        maxHeap.pop();
        minHeap.pop();
    }

    cout << money << endl;
    return 0;
}
