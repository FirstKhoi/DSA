#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://leetcode.com/problems/interval-list-intersections/?envType=problem-list-v2&envId=2fh4qdsc
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n = firstList.size(), m = secondList.size();
        vector<vector<int>> ans;
        int i = 0, j = 0;
        while(i < n && j < m){
            int start = max(firstList[i][0], secondList[j][0]);
            int end = min(firstList[i][1], secondList[j][1]);
            if(start <= end){
                ans.push_back({start, end});
            }
            if(firstList[i][1] < secondList[j][1]){
                i++;
            } else {
                j++;
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