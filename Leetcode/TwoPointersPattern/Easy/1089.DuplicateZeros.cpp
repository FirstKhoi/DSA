#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://leetcode.com/problems/duplicate-zeros/description/?envType=problem-list-v2&envId=2fh4qdsc
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
    int n = arr.size();
    int count0 = 0;
    for(int i = 0; i < n; ++i){
        if(arr[i] == 0){
            count0++;
        }
    }
    int newArraySize = n + count0;
    vector<int> newArr(newArraySize);
    int j = 0;
    for(int i = 0; i < n; ++i){
        if(arr[i] == 0){
            newArr[j++] = 0;
            if(j < newArraySize) newArr[j++] = 0; // Duplicate zero
        } else {
            newArr[j++] = arr[i];
        }
    }
    // Copy back to original array
    for(int i = 0; i < n; ++i){
        arr[i] = newArr[i];
    }
    }
};      

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    Solution sol;
    vector<int> arr = {1,0,2,3,0,4,5,0};
    sol.duplicateZeros(arr);
    for(int i : arr) cout << i << " ";
    cout << endl;
    return 0;
}
