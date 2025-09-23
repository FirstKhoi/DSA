#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

vector<vector<int>> graph;
vector<int> indegree;
vector<int> topoSort(int n) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            pq.push(i);
        }
    }

    vector<int> res;
    while(!pq.empty()) {
        int u = pq.top(); pq.pop();
        res.push_back(u);

        for(int &v : graph[u]) {
            indegree[v]--;
            if(indegree[v] == 0) {
                pq.push(v);
            }
        }
    }
    if(res.size() < n) return {};
    return res;
}

int main() {
	int tc = 1;
	int n, m;
	while (cin >> n) {
		vector<string> name(n);
		map<string, int> id;
		
		for (int i = 0; i < n; i++) {
			cin >> name[i];
			id[name[i]] = i;
		}
		graph.assign(n, {});
        indegree.assign(n, 0);
		cin >> m;
		string name1, name2;
		for (int i = 0; i < m; i++) {
			cin >> name1 >> name2;
			int u = id[name1], v = id[name2];
            graph[u].push_back(v);
            indegree[v]++;
		}
		vector<int>topo_ord = topoSort(n);
		
		cout << "Case #" << tc++ << ": Dilbert should drink beverages in this order:";
		for (int i = 0; i < topo_ord.size(); i++) {
			cout << " " << name[topo_ord[i]];
		}
		cout << "." << endl << endl;		
        string blank;
        getline(cin, blank);
	}
	
}