#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, xres = 0, yres = 0, zres = 0;
    cin >> n;
    while (n--) {
        int x, y, z;
        cin >> x >> y >> z;
        xres += x;
        yres += y;
        zres += z;
    }
    if(xres == 0 && yres == 0 && zres == 0) cout << "YES";
    else cout << "NO";
    return 0;
}
