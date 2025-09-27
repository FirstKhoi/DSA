INF = 1e9 + 7

class Edge:
    def __init__(self, source, target, weight):
        self.source = source
        self.target = target
        self.weight = weight

def BellmanFord(s):
    dist = [INF] * n
    dist[s] = 0
    
    for i in range(n - 1):
        for j in range(len(graph)):
            edge = graph[j]
            u, v, w = edge.source, edge.target, edge.weight
            if dist[u] != INF and dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                
    for j in range(len(graph)):
        edge = graph[j]
        u, v, w = edge.source, edge.target, edge.weight
        if dist[u] != INF and dist[u] + w < dist[v]:
            return False
    return True

T = int(input())

for _ in range(T):
    n, m = map(int, input().split())
    graph = []
    
    for i in range(m):
        u, v, w = map(int, input().split())
        graph.append(Edge(u, v, w))
        
    print("possible" if not BellmanFord(0) else "not possible")
            