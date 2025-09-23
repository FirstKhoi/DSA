#include <iostream>
#include <string>
#define MAX 26
using namespace std;

struct TrieNode {
    TrieNode* child[MAX];
    int countWord;     
    int totalWords; 
};  

TrieNode* newNode() {
    TrieNode* node = new TrieNode();
    node->countWord = 0;
    node->totalWords = 0;
    for(int i = 0; i < MAX; i++) {
        node->child[i] = nullptr;
    }
    return node;
}

void addWord(TrieNode* root, string s) {
    TrieNode* curr = root;
    for(char &c : s) {
        int pos = c - 'a';
        if(curr->child[pos] == nullptr) {
            curr->child[pos] = newNode();
        }
        curr = curr->child[pos];
        curr->totalWords++;
    }
    curr->countWord++;
}

int findWord(TrieNode* root, string s) {
    TrieNode* curr = root;
    for(char &c : s) {
        int pos = c - 'a';
        if(curr->child[pos] == nullptr) {
            return 0;
        }
        curr = curr->child[pos];
    }
    return curr->totalWords;
}

int main() {
    int n; cin >> n;
    string q, s;
    TrieNode *root = newNode();
    for(int i = 0; i < n; i++) {
        cin >> q;
        if(q == "add") {
            cin >> s;
            addWord(root, s);
        }
        else if(q == "find") {
            cin >> s;
            cout << findWord(root, s) << endl;
        }
    }     
    return 0;
}