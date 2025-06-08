#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0.0;

        sort(nums.begin(), nums.end());
        int i = 0, j = n - 1;
        double minAvg = 1e18;

        while (i < j) {
            double avg = (nums[i] + nums[j]) / 2.0;
            minAvg = min(minAvg, avg);
            ++i;
            --j;
        }

        return minAvg;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    return 0;
}