import queue
INF = 10 ** 9

def BellmanFord(s):
    dist[s] = 0
    
    for i in range(N - 1):
        for j in range(M):
            u, v, w = graph[j]
            if dist[u] != INF and dist[u] + w < dist[v]:
                dist[v] = dist[u] + w

    for i in range(N - 1):
        for j in range(M):
            u, v, w = graph[j]
            if dist[u] != INF and dist[u] + w < dist[v]:
                dist[v] = -INF              
while True:
    N, M, Q, S = map(int, input().split())
    if N == 0:
        break
    graph = []
    dist = [INF] * (N + 1)
    for i in range(M):
        u, v, w = map(int, input().split())
        graph.append((u, v, w))
        
    BellmanFord(S)
    for _ in range(Q):
        f = int(input())
        if dist[f] == INF:
            print("Impossible")
        elif dist[f] == -INF:
            print("-Infinity")
        else:   
            print(dist[f])
    print()