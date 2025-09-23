#include <iostream>
#include <string>
#define MAX 26
using namespace std;

struct TrieNode {
    TrieNode *child[MAX];
    bool isEndOfWord;
    bool hasChild;
};

struct TrieNode *newNode() {
    TrieNode *node = new TrieNode();
    node->isEndOfWord = false;
    node->hasChild = false;
    for(int i = 0; i < 26; i++) {
        node->child[i] = nullptr;
    }
    return node;
};

bool insertPass(TrieNode *root, string s) {
    TrieNode *curr = root;
    bool isVulnerable = false;

    for(char &c : s) {
        int pos = c - 'a';
        if(curr->child[pos] == nullptr) {
            curr->child[pos] = newNode();
        }
        curr = curr->child[pos];
        if(curr->isEndOfWord) {
            isVulnerable = true;
        }
    }
    
    curr->isEndOfWord = true;
    
    for(int i = 0; i < MAX; i++) {
        if(curr->child[i] != nullptr) {
            curr->hasChild = true;
            isVulnerable = true;
            break;
        }
    }
    
    return isVulnerable;
}

int main() {
    int n;
    cin >> n;
    string s;
    TrieNode *root = newNode();
    bool vulnerable = false;
    
    for(int i = 0; i < n; i++) {
        cin >> s;
        if(insertPass(root, s)) {
            vulnerable = true;
        }
    }
    
    if(vulnerable) {
        cout << "vulnerable" << endl;
    } else {
        cout << "non vulnerable" << endl;
    }
    
    return 0;
}