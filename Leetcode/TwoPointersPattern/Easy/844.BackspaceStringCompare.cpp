#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://leetcode.com/problems/backspace-string-compare/description/?envType=problem-list-v2&envId=two-pointers
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1, j = t.size() - 1;
        int skipS = 0, skipT = 0;
    
        while(i >= 0 || j >= 0){
            while(i >= 0 && (s[i] == '#' || skipS > 0)){
                if(s[i] == '#') skipS++;
                else skipS--;
                i--;
            }
            while(j >= 0 && (t[j] == '#' || skipT > 0)){
                if(t[j] == '#') skipT++;
                else skipT--;
                j--;
            }
            
            if(i >= 0 && j >= 0 && s[i] != t[j]) return false;
            if((i >= 0) != (j >= 0)) return false; 
            i--; j--;
        }
        return true;
    }
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    Solution sol;
    string s = "ab#c";
    string t = "ad#c";
    bool result = sol.backspaceCompare(s, t);
    cout << (result ? "True" : "False") << endl;
    string s2 = "ab##";
    string t2 = "c#d#";
    bool result2 = sol.backspaceCompare(s2, t2);
    cout << (result2 ? "True" : "False") << endl;
    return 0;
}