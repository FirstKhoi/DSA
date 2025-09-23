#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX 26
//not done yet
int countSuffixes;
int suffixStart[MAX + 5];

struct Node {
	Node* child[MAX];
};
Node* newNode() {
	Node* node = new Node;
	for (int i = 0; i < MAX; ++i)
		node->child[i] = NULL;
	return node;
};
void addWord(Node* root, string s) {
	int ch;
	Node* temp = root;
	for (int i = 0; i < s.size(); ++i) {
		ch = s[i] - 'a';
		if (temp->child[ch] == NULL)
			temp->child[ch] = newNode();
		temp = temp->child[ch];
	}
}
void reverse(string& s) {
	string t = "";
	for (int i = s.size() - 1; i >= 0; --i)
		t = t + s[i];
	s = t;
}
void countSuffix(Node* root, int height) {
	for (int i = 0; i < MAX; ++i)
		if (root->child[i] != NULL) {
			countSuffixes++;
			if (height > 0)
				suffixStart[i]++;
			countSuffix(root->child[i], height + 1);
		}
}
long long countWord(Node* root, int height) {
	long long res = 0;
	if (height > 0)
		res = countSuffixes;
	for (int i = 0; i < MAX; ++i)
		if (root->child[i] != NULL) {
			if (height > 0)
				res -= suffixStart[i];
			res += countWord(root->child[i], height + 1);
		}
	return res;
}
int main() {
	int p, s;
	while (cin >> p >> s && p) {
		string pre, suf;
		Node* Prefix = newNode(), * Suffix = newNode();
		while (p--) {
			cin >> pre;
			addWord(Prefix, pre);
		}
		while (s--) {
			cin >> suf;
			reverse(suf);
			addWord(Suffix, suf);
		}
		for (int i = 0; i < MAX; ++i)
			suffixStart[i] = 0;
		countSuffixes = 0;
		countSuffix(Suffix, 0);
		long long ans = countWord(Prefix, 0);
		cout << ans << endl;
	}
	return 0;
}