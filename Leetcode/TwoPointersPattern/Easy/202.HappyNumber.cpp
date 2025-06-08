#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://leetcode.com/problems/happy-number/?envType=problem-list-v2&envId=two-pointers
class Solution {
public:
    int sumOfSquares(int x) {
        int sum = 0;
        while (x > 0) {
            int digit = x % 10;
            sum += digit * digit;
            x /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = sumOfSquares(slow);
            fast = sumOfSquares(sumOfSquares(fast));
        } while (slow != fast);
        return slow == 1;
    }
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    Solution sol;
    cout << sol.isHappy(19) << endl;  // Output: 1 (true)
    return 0;
}