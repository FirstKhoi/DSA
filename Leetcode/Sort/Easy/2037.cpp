#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/description/?envType=problem-list-v2&envId=sorting
class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        
        int moves = 0;
        for(int i = 0; i < seats.size(); i++){
            moves += abs(seats[i] - students[i]);
        }
        
        return moves;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    Solution sol;
    vector<int> seats = {3, 1, 5};
    vector<int> students = {2, 7, 4};
    cout << sol.minMovesToSeat(seats, students) << endl; // Output: 4
    return 0;
}