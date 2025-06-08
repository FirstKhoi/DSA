#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;

int prime[1000001];
void sang(){
    for(int i = 0; i <= 1000000; ++i){
        prime[i] = 1;
    }
    prime[0] = 0;
    prime[1] = 0;
    for(int i = 2; i <= sqrt(1000000); ++i){
        if(prime[i] == 1){
            for(int j = i * i; j <= 1000000; j+=i){
                prime[j] = 0;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    sang();
    return 0;
}