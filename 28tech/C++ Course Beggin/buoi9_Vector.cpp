#include <bits/stdc++.h>
#include <vector>
using namespace std;
//nhap mang vector cach1
void nhapVectorC1(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++){
        cin >> v[i];
    }
}

//nhap mang vector cach 2
void nhapVectorC2(){
    vector<int> v;
    int n; cin >> n;
    for(int i = 0 ; i < n ; i++){
        int tmp; cin >> tmp;
        v.push_back(v[i]);
    }
}

//iterator
void vectorIterator(){
    vector<int> v = {3, 5, 2, 8, 6, 7, 5, 1, 4, 9};
    vector<int>::iterator it = v.begin() + 4;
    cout << *it << endl; 
    it +=3; 
    cout << *it << endl;
    it -= v[2];
    cout << *it << endl;
    
    v.insert(v.begin() + 6, 1000);
    
    for(int x : v){
        cout << x << " ";
    }
    
    cout << endl;
    
    for(int i = 0 ; i < v.size(); i++){
        cout << v[i] << " ";
    }
    
    cout << endl;
    
    for(it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    
    cout << endl;

    v.pop_back();
    for(int x : v){
        cout << x << " ";
    }
    cout << endl;

    v.push_back(9);
    for(int x : v){
        cout << x << " ";
    }
    cout << endl;

}

void test(){
        int n; cin >> n;
        vector<int> v(n);
        for(int i = 0; i < v.size(); i++){
            int x;
            cin >> v[i];
            if(v[i] == 1){
                cin >> x;
                v.push_back(x);
            }
            else{
                if(!v.empty()/*hoặc check v.size() > 0)*/){
                    v.pop_back();
                }
            }
        }
        if(v.empty()) cout << "EMPTY" << endl;
        else {
            for(int x : v){
                cout << x << " ";
            }
        }
    }

int tong(vector<int> v){
    int sum = 0;
    for(int x : v){
        sum += x;
    }
    return sum;
}

void nhap(vector<int> &v){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int tmp; cin >> tmp;
        v.push_back(tmp);
    }
}

bool isPrime(int n){
    for(int i = 2 ; i * i <= n ; i++){
        if(n % i == 0) return false;
    }
    return n > 1;
}

vector<int> prime_list(vector<int> v){
    vector<int> res;
    for(int x : v){
        if(isPrime(x)){
            res.push_back(x);
        }
    }
    return res;
}

void in(vector<int> v){
    for(int x : v){
        cout << x << " ";
    }
    cout << endl;
}

int main(){
    int n, q; cin >> n >> q;

    // Use a 2D vector to store the input table
    vector<vector<int>> table(n);

    for(int i = 0; i < n; i++){
        int m; cin >> m;

        // Resize and initialize the inner vectors in one step using an initializer list
        table[i].resize(m);
        for(int j = 0; j < m; j++){
            cin >> table[i][j];
        }
    }

    // Use a loop to process all queries efficiently
    while(q--){
        int x, y;
        cin >> x >> y;

        // Output the required element in one line without any unnecessary operations
        cout << table[x - 1][y - 1] << endl;
    }
    return 0;
}