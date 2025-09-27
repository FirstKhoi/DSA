graph = []
dist = []
visited = []

def dfs(st):
    s = [st]
    visited[st] = True

    while (s):
        u = s.pop()
        
        for v in graph[u]:
            if not visited[v]:
                visited[v] = True
                dist[v] = dist[u] + 1
                s.append(v)
                
V = int(input())
graph = [[] for _ in range(V + 1)]
dist = [0] * (V + 1)
visited = [False] * (V + 1)
E = V - 1

for _ in range (E):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)
dfs(1)
ans = 0
minDist = float('inf')

q = int(input())

for _ in range (q):
    u = int(input())
    if(dist[u] < minDist or (dist[u] == minDist and u < ans)):
        minDist = dist[u]
        ans = u
        
print(ans)


        
        