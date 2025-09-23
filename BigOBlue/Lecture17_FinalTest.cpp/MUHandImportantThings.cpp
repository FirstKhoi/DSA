#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> tasks(n);
    for (int i = 0; i < n; ++i) {
        cin >> tasks[i].first;
        tasks[i].second = i + 1;
    }
    
    sort(tasks.begin(), tasks.end());
    
    vector<int> initial_plan(n);
    for (int i = 0; i < n; ++i) {
        initial_plan[i] = tasks[i].second;
    }
    
    vector<vector<int>> plans = {initial_plan};
    
    for (int i = 0; i < n - 1 && plans.size() < 3; ++i) {
        if (tasks[i].first == tasks[i + 1].first) {
            vector<int> new_plan = plans.back();
            swap(new_plan[i], new_plan[i + 1]);
            plans.push_back(new_plan);
        }
    }
    
    if (plans.size() < 3) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (const auto& plan : plans) {
            for (int i = 0; i < n; ++i) {
                cout << plan[i] << (i == n - 1 ? '\n' : ' ');
            }
        }
    }
    
    return 0;
}