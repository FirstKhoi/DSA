import queue
graph = [[]]
dist = []
INF = 10 ** 9

class Edge:
    def __init__(self, weight, id):
        self.weight = weight
        self.id = id
    def __lt__(self, other):
        return self.weight < other.weight
    
def Dijkstra(s, N):
    dist = [INF] * (N + 1)
    pq = queue.PriorityQueue()
    pq.put(Edge(0, s))
    dist[s] = 0
    
    while not pq.empty():
        top = pq.get()
        u = top.id
        w = top.weight
        if w > dist[u]:
            continue
    
        for v in graph[u]:
            if w + v.weight < dist[v.id]:
                dist[v.id] = w + v.weight
                pq.put(Edge(dist[v.id], v.id))
    return dist

T = int(input())
for tc in range(1, T + 1):
    N = int(input())
    R = int(input())
    graph = [[] for _ in range(N + 1)]
    for _ in range(R):
        u, v = map(int, input().split())
        graph[u].append(Edge(1, v))
        graph[v].append(Edge(1, u))
        
    s, d = map(int, input().split())
    distS = Dijkstra(s, N)
    distD = Dijkstra(d, N)
    res = 0
    for i in range(N):
        res = max(res, distS[i] + distD[i])
    print("Case {}: {}".format(tc, res))
