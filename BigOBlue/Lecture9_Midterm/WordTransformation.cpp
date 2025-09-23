#include <bits/stdc++.h>
using namespace std;

int main() {
        int N;
        cin >> N;
        
        while (N--) {
            vector<string> dict;
            string word;
            
            // Read dictionary
            while (cin >> word && word != "*") {
                dict.push_back(word);
            }
            
            int V = dict.size();
            vector<vector<int>> graph(V);
            
            // Build graph - connect words that differ by exactly one character
            for (int u = 0; u < V - 1; u++) {
                for (int v = u + 1; v < V; v++) {
                    if (dict[u].size() == dict[v].size()) {
                        int differences = 0;
                        
                        for (int i = 0; i < dict[u].size() && differences <= 1; i++) {
                            if (dict[u][i] != dict[v][i]) differences++;
                        }
                        
                        if (differences == 1) {
                            graph[u].push_back(v);
                            graph[v].push_back(u);
                        }
                    }
                }
            }
            
            cin.ignore();
            string line, sWord, fWord;
            
            // Process queries
            while (getline(cin, line) && !line.empty()) {
                stringstream ss(line);
                ss >> sWord >> fWord;
                
                int s = find(dict.begin(), dict.end(), sWord) - dict.begin();
                int f = find(dict.begin(), dict.end(), fWord) - dict.begin();
                
                // BFS to find shortest path
                vector<int> dist(V, -1);
                queue<int> q;
                q.push(s);
                dist[s] = 0;
                
                while (!q.empty() && dist[f] == -1) {
                    int u = q.front();
                    q.pop();
                    
                    for (int v : graph[u]) {
                        if (dist[v] == -1) {
                            dist[v] = dist[u] + 1;
                            q.push(v);
                        }
                    }
                }
                
                cout << sWord << " " << fWord << " " << dist[f] << endl;
            }
            
            if (N > 0) cout << endl;
        }
        return 0;
    }
