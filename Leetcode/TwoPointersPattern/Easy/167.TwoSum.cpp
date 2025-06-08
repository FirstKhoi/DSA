#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://leetcode.com/problems/two-sum/description/?envType=problem-list-v2&envId=array
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Tạo các cặp (giá trị, chỉ số) để giữ vị trí gốc
        vector<pair<int, int>> numWithIndex;
        numWithIndex.reserve(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            numWithIndex.emplace_back(nums[i], i);
        }
        
        // Sắp xếp theo giá trị
        sort(numWithIndex.begin(), numWithIndex.end());
        
        // Kỹ thuật hai con trỏ
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int sum = numWithIndex[left].first + numWithIndex[right].first;
            if (sum == target) {
                return { numWithIndex[left].second, numWithIndex[right].second };
            }
            if (sum < target) left++;
            else right--;
        }
        
        return {};
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
}