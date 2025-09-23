#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> parent, ranks;

int findSet(int u) {
    if(parent[u] != u) parent[u] = findSet(parent[u]);
    return parent[u];
}

void unionSet(int u, int v) {
    int pu = findSet(u);
    int pv = findSet(v);
    
    if(pu == pv) return;
    
    if(ranks[pu] > ranks[pv]) {
        parent[pv] = pu;
    } else if(ranks[pu] < ranks[pv]) {
        parent[pu] = pv;
    } else {
        parent[pv] = pu;
        ranks[pu]++;
    }
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    
    vector<int> p(n);
    unordered_map<int, int> pos; 
    
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
    }
    
    parent.assign(n, 0);
    ranks.assign(n, 0);
    for(int i = 0; i < n; i++) {
        parent[i] = i;
        ranks[i] = 0;
    }
    
    for(int i = 0; i < n; i++) {
        int complement_a = a - p[i];
        int complement_b = b - p[i];
        
        if(pos.find(complement_a) != pos.end()) {
            unionSet(i, pos[complement_a]);
        }
        if(pos.find(complement_b) != pos.end()) {
            unionSet(i, pos[complement_b]);
        }
    }

    vector<int> res(n, -1);
    unordered_map<int, int> component_assignment;
    
    bool possible = true;
    
    for(int i = 0; i < n; i++) {
        int root = findSet(i);
        int complement_a = a - p[i];
        int complement_b = b - p[i];
        
        bool has_a_pair = pos.find(complement_a) != pos.end();
        bool has_b_pair = pos.find(complement_b) != pos.end();
        
        if(component_assignment.find(root) == component_assignment.end()) {
            if(has_a_pair && !has_b_pair) {
                component_assignment[root] = 0;
            } else if(!has_a_pair && has_b_pair) {
                component_assignment[root] = 1;
            } else if(has_a_pair && has_b_pair) {
                component_assignment[root] = 0; 
            } else {
                possible = false; 
                break;
            }
        }
        res[i] = component_assignment[root];
    }
    
    if(!possible) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for(int i = 0; i < n; i++) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}