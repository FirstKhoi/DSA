#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> dna = {'A', 'C', 'G', 'T'};
int res = 0;

struct TrieNode {
    struct TrieNode *child[4];
    int maxWeight;
};

struct TrieNode *newNode() {
    struct TrieNode *node = new TrieNode;
    node->maxWeight = 0;
    for(int i = 0; i < 4; i++) {
        node->child[i] = nullptr;
    }
    return node;
}

void insertWord(struct TrieNode *root, string s) {
    TrieNode *curr = root;
    for(int i = 0; i < s.size(); i++) {
        int pos = find(dna.begin(), dna.end(), s[i]) - dna.begin();
        int level = i + 1;

        if(curr->child[pos] == nullptr) {
            curr->child[pos] = newNode();
        }
        curr = curr->child[pos];
        curr->maxWeight++;
        res = max(res, curr->maxWeight * level);
    }
}

int main() {
    int t, n, tc;
    string s;
    cin >> t;

    for (tc = 1; tc <= t; tc++) {
        cin >> n;
        TrieNode* root = newNode();
        res = 0;
    for (int i = 0; i < n; i++) {
        cin >> s;
        insertWord(root, s);
    }

    cout << "Case " << tc << ": " << res << endl;
   }
   return 0;
}