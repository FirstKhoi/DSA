#include <iostream>
using namespace std;

struct TrieNode {
    struct TrieNode *child[10];
    int count;
};

struct TrieNode *newNode() {
    struct TrieNode *node = new TrieNode;
    node->count = 0;
    for(int i = 0; i < 10; i++) {
        node->child[i] = nullptr;
    }
    return node;
};

void addNums(struct TrieNode *root, string s) {
    TrieNode *curr = root;
    for(char &c : s) {
        int pos = c - '0';
        if(curr->child[pos] == nullptr) {
            curr->child[pos] = newNode();
        }
        curr = curr->child[pos];
    }
    curr->count++;
}

bool isConsistent(struct TrieNode *root) {
    if (root->count > 0) {
        for (int i = 0; i < 10; i++) {
            if (root->child[i] != nullptr) {
                return false;
            }
        }
        return true;
    }
    
    for (int i = 0; i < 10; i++) {
        if (root->child[i] != nullptr) {
            if (!isConsistent(root->child[i])) {
                return false;   
            }
        }
    }
    return true;
}

int main() {
    int T, n, tc = 1;
    string s;
    cin >> T;
    while(T--) {
        cin >> n;
        struct TrieNode *root = newNode();
        for(int i = 0; i < n; i++) {
            cin >> s;
            addNums(root, s);
        }
        if(isConsistent(root)) {
            cout << "Case " << tc++ << ": " << "YES" << endl;
        } else {
            cout << "Case " << tc++ << ": " << "NO" << endl;
        }
    }
    return 0;
}