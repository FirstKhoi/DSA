#include <iostream>
#include <vector>
#include <iomanip>
#define MAXA 1000
using namespace std;

vector<double> energy, sumTransfer, left, right, mid;

int main() {
    int n, k;
    cin >> n >> k; 
    vector<int> a(n);
    int sumEnergy = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sumEnergy += a[i];
    }

    int left = 0;
    int right = MAXA;
    while(right - left > 1e-9) {
        int mid = left + (right - left) / 2;
        double sumTransfer = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] > mid) {
                sumTransfer += a[i] - mid;
            }
        }
        if(mid * n < sumEnergy - sumTransfer * k / 100) {
            left = mid;
        }
        else {
            right = mid;
        }
    }
    cout << fixed << setprecision(9) << left << endl;
    return 0;
}