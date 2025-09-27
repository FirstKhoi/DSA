import queue
graph = [[]]
dist = []
INF = 1e9 + 7
class Edge:
    def __init__(self, weight, id):
        self.weight = weight
        self.id = id
    def __lt__(self, other):
        return self.weight < other.weight

def Dijkstra(s, f):
    pq = queue.PriorityQueue()
    pq.put(Edge(0, s))
    dist = [INF] * (N + 1)
    dist[s] = 0
    
    while not pq.empty():
        top = pq.get()
        u = top.id
        w = top.weight
        if(w > dist[u]): continue
        for v in graph[u]:
            if w + v.weight < dist[v.id]:
                dist[v.id] = w + v.weight
                pq.put(Edge(dist[v.id], v.id))
    return dist[f]

T = int(input()) 

for tc in range(T):
    N = int(input()) 
    graph = [[] for i in range(N + 1)]
    cities = []
    
    for i in range(1, N + 1):
        name = input()
        cities.append(name)
        m = int(input())
        
        for j in range(m):
            v, w = map(int, input().split())
            graph[i].append(Edge(w, v))
            
    Q = int(input())
    
    for i in range(Q):
        sCity, fCity = input().split()
        s = cities.index(sCity) + 1
        f = cities.index(fCity) + 1 
        print(Dijkstra(s, f))
    input()
            