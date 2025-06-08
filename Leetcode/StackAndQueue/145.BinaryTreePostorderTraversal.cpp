#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://leetcode.com/problems/binary-tree-postorder-traversal/description/?envType=problem-list-v2&envId=stack
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode* curr = root;
        TreeNode* lastVisited = nullptr;
        while (curr || !s.empty()) {
            while (curr) {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            if (!curr->right || curr->right == lastVisited) {
                result.push_back(curr->val);
                s.pop();
                lastVisited = curr;
                curr = nullptr;
            } else {
                curr = curr->right;
            }
        }
        return result;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    return 0;
}