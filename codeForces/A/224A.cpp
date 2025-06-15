#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    double a = sqrt(1.0 * s1 * s3 / s2);
    double b = sqrt(1.0 * s1 * s2 / s3);
    double c = sqrt(1.0 * s2 * s3 / s1);
    ll P = 4 * (a + b + c);
    cout << P << endl;
    return 0;
}