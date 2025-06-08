#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        int n = nums.size();
        set<double> average;
        sort(nums.begin(), nums.end());
        int l = 0, r = n - 1;
        while(l < r){
            double avg = (nums[l] + nums[r]) / 2.0;
            average.insert(avg);
            l++;
            r--;
        }
        return average.size();
    }
};
    return 0;
}