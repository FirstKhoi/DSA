#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/description/?envType=problem-list-v2&envId=2fh4qdsc
class Solution {
public:
    int minSwaps(string s) {
        int imbalance = 0; 
        int swaps = 0;
        

        for (char ch : s) {
            if (ch == '[') {
                imbalance--; 
            } else { // ch == ']'
                imbalance++; 
            }

            if (imbalance > 0) {
                swaps++;
                imbalance -= 2; 
            }
        }
        return swaps;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    return 0;
}