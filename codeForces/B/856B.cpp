#include <iostream>
#include <string>
#define MAX 26
using namespace std;

struct TrieNode {
    TrieNode *child[MAX];
    int isEnd;
};

struct TrieNode *newNode() {
    TrieNode *node = new TrieNode();
    node->isEnd = false;
    for(int i = 0; i < MAX; i++) {
        node->child[i] == nullptr;
    }
    return node;
};

void insertWord(TrieNode *root, string s) {
    TrieNode *curr = root;

    for(char &c : s) {
        int pos = c - 'a';
        if(curr->child[pos] == nullptr) {
            curr->child[pos] = newNode();
        }
        curr = curr->child[pos];
    }
    curr->isEnd = true;
}

void generatePrefix(TrieNode *root, string s) {
    
}

int main() {
    int T, n;
    string s;
    cin >> T;
    while(T--) {
        cin >> n;
        for(int i  = 0; i < n; i++) {
            cin >> s;
        }
    }
    return 0;
}