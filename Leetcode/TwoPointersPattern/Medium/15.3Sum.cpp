#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://leetcode.com/problems/3sum/description/?envType=problem-list-v2&envId=2fh4qdsc
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < n; ++i){
            if(nums[i] > 0){
                break;
            } else if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            int low = i + 1, high = n - 1;
            while(low < high){
                int sum = nums[i] + nums[low] + nums[high];
                if(sum == 0){
                    ans.push_back({nums[i], nums[low], nums[high]});
                    // Skip duplicates for low and high
                    while(low < high && nums[low] == nums[low + 1]) low++;
                    while(low < high && nums[high] == nums[high - 1]) high--;
                    low++; high--;
                } else if(sum < 0){
                    low++;
                } else {
                    high--;
                }
            }
        }
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    return 0;
}