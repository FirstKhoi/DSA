#include<bits/stdc++.h>
using namespace std;
int main() {
	int n; cin >> n;
	cin.ignore();
	string s;
	getline(cin, s);
	for (char &x : s) {
		if (isupper(x)) {
			x = tolower(x);
		}
	}
	vector<int> cnt(26);
	for (char x : s) {
		if (isalpha(x)) {
			cnt[x - 'a']++;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (cnt[i] == 0) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}