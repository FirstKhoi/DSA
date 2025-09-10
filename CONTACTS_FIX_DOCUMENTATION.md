# Contacts Trie Implementation - Bug Fixes

## Problem Description
The Contacts application had several bugs causing Time Limit Exceeded (TLE) and incorrect results:

1. **addWord function bug**: Current node pointer wasn't being updated when traversing the Trie
2. **findKey function bugs**: 
   - Didn't update the current pointer during traversal
   - Returned a boolean instead of counting matches
3. **Output bug**: The program wasn't correctly outputting the count for each find operation

## Bugs Fixed

### 1. Fixed addWord function
**Before (buggy):**
```cpp
void addWord(string word) {
    TrieNode* current = root;
    for (char ch : word) {
        int index = ch - 'a';
        if (current->children[index] == nullptr) {
            current->children[index] = new TrieNode();
        }
        // BUG: Not updating current pointer
        // current = current->children[index];
        current->count++;  // This increments wrong node
    }
}
```

**After (fixed):**
```cpp
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
```

### 2. Fixed findKey function
**Before (buggy):**
```cpp
bool findKey(string prefix) {
    TrieNode* current = root;
    for (char ch : prefix) {
        int index = ch - 'a';
        if (current->children[index] == nullptr) {
            return false;
        }
        // BUG: Not updating current pointer properly
        // current = current->children[index];
    }
    // BUG: Returns boolean instead of count
    return true;
}
```

**After (fixed):**
```cpp
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
```

### 3. Fixed output in main function
**Before (buggy):**
```cpp
bool result = trie.findKey(word);
// BUG: Not printing the count, just printing boolean result
cout << (result ? 1 : 0) << endl;
```

**After (fixed):**
```cpp
int result = trie.findKey(word);
// FIX: Print the actual count
cout << result << endl;
```

## Test Results
The fixed implementation correctly handles the test case:
- Input: add hack, add hackerrank, find hac, add hacker, find hac
- Output: 2, 3 (correctly counting contacts with prefix "hac")

## Time Complexity
- **addWord**: O(m) where m is the length of the word
- **findKey**: O(p) where p is the length of the prefix
- **Space**: O(ALPHABET_SIZE * N * M) where N is number of words and M is average word length

This implementation efficiently avoids TLE by using optimal Trie traversal.