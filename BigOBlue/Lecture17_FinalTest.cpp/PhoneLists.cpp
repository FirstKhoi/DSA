#include <iostream>
#include <vector>
using namespace std;

struct TrieNode {
    TrieNode *child[10];
    bool isEnd;
    bool hasChild;
};

TrieNode *newNode() {
    TrieNode *node = new TrieNode();
    node->isEnd = false;
    for(int i = 0; i < 10; i++) {
        node->child[i] = nullptr;
    }
    return node;
}

bool insertPhoneNum(TrieNode *root, string s) {
    TrieNode *curr = root;
    bool isConsist = false;
    for(auto &c : s) {
        int pos = c - '0';
        if(curr->child[pos] == nullptr) {
            curr->child[pos] = newNode();
        }
        curr = curr->child[pos];
        if(curr->isEnd) {
            return true;
        }
    }
    curr->isEnd = true;

    for(int i = 0; i < 10; i++) {
        if(curr->child[i] != nullptr) {
            return true;
        }
    }
    return false;
}

int main() {
    int t, n;
    string s;
    cin >> t;        
    while(t--) {
        cin >> n;
        TrieNode *root = newNode();
        bool check = false;
        for(int i = 0; i < n; i++) {
            cin >> s;
            if(insertPhoneNum(root, s)) {
                check = true;
            }
        }
        cout << (check ? "NO" : "YES") << endl;
    }
    return 0;
}