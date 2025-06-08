#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;

//https://leetcode.com/problems/find-the-array-concatenation-value/description/?envType=problem-list-v2&envId=two-pointers
class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        long long concatenationVal = 0;
        while (left < right) {
            int first = nums[left];
            int second = nums[right];
            string s_first = to_string(first);
            string s_second = to_string(second);
            string concatenated_str = s_first + s_second;
            concatenationVal += stoll(concatenated_str);
            left++;
            right--;
        }
        if (left == right) {
            concatenationVal += nums[left];
        }
        return concatenationVal;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    Solution sol;

    // Example 1
    std::vector<int> nums1 = {7, 52, 2, 4};
    long long result1 = sol.findTheArrayConcVal(nums1);
    std::cout << "Example 1 Input: [7, 52, 2, 4]" << std::endl;
    std::cout << "Example 1 Output: " << result1 << std::endl; // Expected: 596

    // Example 2
    std::vector<int> nums2 = {5, 14, 13, 8, 12};
    long long result2 = sol.findTheArrayConcVal(nums2);
    std::cout << "Example 2 Input: [5, 14, 13, 8, 12]" << std::endl;
    std::cout << "Example 2 Output: " << result2 << std::endl; // Expected: 673

    // Example with a single element
    std::vector<int> nums3 = {100};
    long long result3 = sol.findTheArrayConcVal(nums3);
    std::cout << "Example 3 Input: [100]" << std::endl;
    std::cout << "Example 3 Output: " << result3 << std::endl; // Expected: 100

    // Example with an even number of elements
    std::vector<int> nums4 = {1, 2, 3, 4};
    long long result4 = sol.findTheArrayConcVal(nums4);
    std::cout << "Example 4 Input: [1, 2, 3, 4]" << std::endl;
    std::cout << "Example 4 Output: " << result4 << std::endl; // Expected: 14 + 23 = 37

    return 0;
}