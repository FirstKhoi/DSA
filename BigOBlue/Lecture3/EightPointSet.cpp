#include<bits/stdc++.h>
using namespace std;
//https://bigocoder.com/courses/252/lectures/3814/problems/1055?view=statement
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<pair<int, int>> points;
    for (int i = 0; i < 8; i++) {
        int a, b;
        cin >> a >> b;
        points.push_back({a, b});
    }

    set<pair<int, int>> point_set(points.begin(), points.end());
    if (point_set.size() < 8) {
        cout << "ugly\n";
        return 0;
    }

    set<int> xs, ys;
    for (auto &p : points) {
        xs.insert(p.first);
        ys.insert(p.second);
    }

    if (xs.size() != 3 || ys.size() != 3) {
        cout << "ugly\n";
        return 0;
    }

    vector<int> x_coords(xs.begin(), xs.end());
    vector<int> y_coords(ys.begin(), ys.end());

    bool ok = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) continue;
            if (point_set.count({x_coords[i], y_coords[j]}) == 0) {
                ok = false;
                break;
            }
        }
    }

    cout << (ok ? "respectable" : "ugly") << "\n";
    return 0;
}