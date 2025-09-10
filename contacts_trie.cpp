#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    int count;
    
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        count = 0;
    }
};

class Trie {
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    // FIXED: Correctly traverse the Trie when adding words
    void addWord(string word) {
        TrieNode* current = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (current->children[index] == nullptr) {
                current->children[index] = new TrieNode();
            }
            // FIX: Update current pointer to traverse properly
            current = current->children[index];
            current->count++;  // Increment count at each node in the path
        }
    }
    
    // FIXED: Count all words that start with given prefix
    int findKey(string prefix) {
        TrieNode* current = root;
        for (char ch : prefix) {
            int index = ch - 'a';
            if (current->children[index] == nullptr) {
                return 0;  // No words with this prefix
            }
            // FIX: Update current pointer to traverse properly
            current = current->children[index];
        }
        // FIX: Return the count instead of boolean
        return current->count;
    }
};

int main() {
    int n;
    cin >> n;
    
    Trie trie;
    
    for (int i = 0; i < n; i++) {
        string operation, word;
        cin >> operation >> word;
        
        if (operation == "add") {
            trie.addWord(word);
        } else if (operation == "find") {
            int result = trie.findKey(word);
            // FIX: Print the actual count
            cout << result << endl;
        }
    }
    
    return 0;
}