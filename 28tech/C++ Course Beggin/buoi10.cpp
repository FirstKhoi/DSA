#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    set<int> se;
    for(int i= 0; i < n ; i++){
        int tmp;
        cin >> tmp;
        se.insert(tmp);
    }
    cout << "Set elements: ";
    for(int x : se){
        cout << x << " ";
    }
    cout << endl;
    // Sets in C++ do not provide direct access to their elements by index.
    // Instead, we can use iterators or convert the set into a vector.
    vector<int> vec(se.begin(), se.end());
    for(auto it = vec.rbegin(); it != vec.rend(); ++it){
        cout << *it << " ";
    }
    if (!se.empty()) {
        auto smallest = *se.begin();
        auto largest = *se.rbegin();

        cout << "Smallest element: " << smallest << "\n";
        cout << "Largest element: " << largest << "\n";
    }

    set<int> se1 = {1, 2, 3, 4, 5, 6};
    cout << *se.begin() << endl;
    cout << *se.rbegin() << endl;

    auto it = se.find(4);
    if(it == se.end()){
        cout << "NOT FOUND \n";
    }
    else cout << "FOUND!" << endl;

    string s = "ky thuat lap trinh";
    int res = isalpha(s[1]);
    cout << res << endl;
    char c = s[2] - 32;
    return 0;
}