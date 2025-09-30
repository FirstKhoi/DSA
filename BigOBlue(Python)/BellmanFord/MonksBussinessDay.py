INF = 10 ** 9

def BellmanFord(s):
    dist = [INF] * (N + 1)
    dist[s] = 0

    for i in range(N - 1):
        for j in range(M):
            u, v, w = graph[j]
            
            if dist[u] != INF and dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
    

    for j in range(M):
        u, v, w = graph[j]
        if dist[u] != INF and dist[u] + w < dist[v]:
            return True
        
T = int(input())
for _ in range(T):
    N, M = map(int, input().split())
    graph = []
    for i in range(M):
        u, v, w = map(int, input().split())
        graph.append((u, v, -w))
        
    print("Yes" if BellmanFord(1) else "No")