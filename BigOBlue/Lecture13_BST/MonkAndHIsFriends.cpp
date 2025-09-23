#include<iostream>
using namespace std;

struct Node {
    long long key;
    Node *left;
    Node *right;
};

Node *createNode(long long x) {
    Node *newnode = new Node;
    newnode -> key = x;
    newnode -> left = newnode -> right = NULL;
    return newnode;
}

Node *insertNode(Node *root, long long x) {
    if(root == NULL) {
        return createNode(x);
    }
    if(x < root->key) {
        root->left = insertNode(root->left, x);
    } else if(x > root->key) {
        root->right = insertNode(root->right, x);
    }
    return root;
}

Node *searchNode(Node *root, long long x) {
    if(root == NULL || root->key == x) {
        return root;
    } if(root->key < x) {
        return searchNode(root->right, x);
    }
    return searchNode(root->left, x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n, m;
    long long temp;
    cin >> T;
    while(T--) {
        Node *root = NULL;
        cin >> n >> m;
        for(int i = 0; i < n; i++) {
            cin >> temp;
            root = insertNode(root, temp);
        }
        
        for(int i = 0; i < m ; i++) {
            cin >> temp;
            if(searchNode(root, temp) != NULL) {
                cout << "YES" << endl;
            } else cout << "NO" << endl;
            insertNode(root, temp);
        }
    }
    return 0;
}