#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/?envType=problem-list-v2&envId=two-pointers
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> merged;
        int i = 0, j = 0;
        
        // Merge arrays while both have elements
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i][0] == nums2[j][0]) {
                // Same ID, sum the values
                merged.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                i++;
                j++;
            } else if (nums1[i][0] < nums2[j][0]) {
                // nums1's ID is smaller, add it
                merged.push_back(nums1[i]);
                i++;
            } else {
                // nums2's ID is smaller, add it
                merged.push_back(nums2[j]);
                j++;
            }
        }       
        
        // Add remaining elements
        while (i < nums1.size()) {
            merged.push_back(nums1[i++]);
        }
        
        while (j < nums2.size()) {
            merged.push_back(nums2[j++]);
        }   
        
        return merged;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    Solution sol;

    // Example 1
    vector<vector<int>> nums1 = {{1, 2}, {2, 3}, {4, 5}};
    vector<vector<int>> nums2 = {{1, 3}, {3, 4}, {4, 6}};
    vector<vector<int>> result1 = sol.mergeArrays(nums1, nums2);
    cout << "Example 1 Output: ";
    for (const auto& vec : result1) {
        cout << "[" << vec[0] << ", " << vec[1] << "] ";
    }
    cout << endl; // Expected: [[1, 5], [2, 3], [3, 4], [4, 11]]

    // Example 2
    vector<vector<int>> nums3 = {{1, 2}, {3, 4}};
    vector<vector<int>> nums4 = {{2, 3}, {5, 6}};
    vector<vector<int>> result2 = sol.mergeArrays(nums3, nums4);
    cout << "Example 2 Output: ";
    for (const auto& vec : result2) {
        cout << "[" << vec[0] << ", " << vec[1] << "] ";
    }
    cout << endl; // Expected: [[1, 2], [2, 3], [3, 4], [5, 6]]

    return 0;
}