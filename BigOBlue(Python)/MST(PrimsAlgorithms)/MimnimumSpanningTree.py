import queue
INF = 10 ** 9

class Edge:
    def __init__(self, weight, id):
        self.weight = weight
        self.id = id
    def __lt__(self, other):
        return self.weight < other.weight

def Prim(s, N, graph):
    dist = [INF] * N
    visited = [False] * N
    dist[s] = 0
    pq = queue.PriorityQueue()
    pq.put(Edge(0, s))
    
    while not pq.empty():
        top = pq.get()
        u = top.id
        if visited[u]:
            continue
        visited[u] = True
        
        for edge in graph[u]:
            v = edge.id
            w = edge.weight
            if not visited[v] and dist[v] > w:
                dist[v] = w
                pq.put(Edge(w, v))
    
    totalCost = 0
    for i in range(N):
        totalCost += dist[i]
    return totalCost
    
def solve():
    N, M = map(int, input().split())
    graph = [[] for _ in range(N)]
    for i in range(M):
        u, v, w = map(int, input().split())
        u -= 1
        v -= 1 
        graph[u].append(Edge(w, v))
        graph[v].append(Edge(w, u))
    print(Prim(0, N, graph))
    
solve()