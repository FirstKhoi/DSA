import queue


def bfs(s):
    q = queue.Queue()
    visited[s] = True
    q.put(s)
    
    while not q.empty():
        u = q.get()
        
        for v in graph[u]:
            if not visited[v]:
                visited[v] = True
                q.put(v)
                dist[v] = dist[u] + 1
                
Q = int(input())
    
for _ in range (Q):
    V, E = map(int, input().split())
    
    graph = [[] for _ in range(V + 1)]
    visited = [False] * (V + 1)
    dist = [0] * (V + 1)
    
    for i in range (E):
        u, v = map(int, input().split())
        graph[u].append(v)
        graph[v].append(u)
        
    s = int(input())
    bfs(s)
    
    for i in range(1, V + 1):
        if i == s: continue
        print(dist[i] * 6 if visited[i] else -1, end = ' ')
    print()