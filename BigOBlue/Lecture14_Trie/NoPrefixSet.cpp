#include <iostream>
#include <string>
#define MAX 26
using namespace std;

struct TrieNode {
    TrieNode *child[MAX];
    int flag; 
};

struct TrieNode *newNode() {
    TrieNode *node = new TrieNode();
    node->flag = 0;
    for (int i = 0; i < MAX; i++) {
        node->child[i] = nullptr;
    }
    return node;
}

bool insertWord(TrieNode *root, string s) {
    TrieNode *curr = root;

    for (char &c : s) {
        int pos = c - 'a';
        if (curr->child[pos] == nullptr) {
            curr->child[pos] = newNode();
        }
        curr = curr->child[pos];
        if (curr->flag > 0)
            return false;
    }
    curr->flag++;
    for (int i = 0; i < MAX; i++) {
        if (curr->child[i] != nullptr) return false;
    }

    return true;
}

int main() {
    int n;
    cin >> n;
    string s;
    TrieNode *root = newNode();
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (!insertWord(root, s)) {
            cout << "BAD SET" << endl;
            cout << s << endl;
            return 0;
        }
    }
    cout << "GOOD SET" << endl;
    return 0;
}
