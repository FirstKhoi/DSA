#include <iostream>
#include <string>
#define MAX 26
using namespace std;

struct TrieNode {
    TrieNode* child[MAX];
    int countWord;
};

struct TrieNode* newNode() {
    TrieNode* node = new TrieNode();
    node->countWord = -1;
    for(int i = 0; i < MAX; i++) {
        node->child[i] = nullptr;
    }
    return node;
}; 

void addWord(TrieNode* root, string s, int w) {
    TrieNode* curr = root;
    for(char &c : s) {
        int pos = c - 'a';
        if(curr->child[pos] == nullptr) {
            curr->child[pos] = newNode();
        }
        curr = curr->child[pos];
        curr->countWord = max(curr->countWord, w);
    }
}

int findWord(TrieNode* root, string s) {
    TrieNode* curr = root;
    for(char &c : s) {
        int pos = c - 'a';
        if(curr->child[pos] == nullptr) {
            return -1;       
        }
        curr = curr->child[pos];
    }
    return curr->countWord;
}

int main() {
    int n, q, w;
    cin >> n >> q;
    TrieNode* root = newNode();
    string s;
    for(int i = 0; i < n; i++) {
        cin >> s >> w;
        addWord(root, s, w);
    }
    string t;
    for(int i = 0; i < q; i++) {
        cin >> t;
        cout << findWord(root, t) << endl;
    }
    return 0;
}