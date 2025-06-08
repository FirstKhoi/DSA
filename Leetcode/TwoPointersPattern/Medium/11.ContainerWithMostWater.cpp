#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://leetcode.com/problems/container-with-most-water/description/?envType=problem-list-v2&envId=2fh4qdsc
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int maxArea = 0;
        
        while(left < right) {
            int currentHeight = min(height[left], height[right]);
            int currentWidth = right - left;
            maxArea = max(maxArea, currentHeight * currentWidth);
            
            if(height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxArea;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    return 0;
}