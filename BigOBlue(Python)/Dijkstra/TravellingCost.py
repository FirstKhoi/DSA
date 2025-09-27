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
    
def Dijkstra(s):
    pq = queue.PriorityQueue()
    pq.put(Edge(0, s))
    dist[s] = 0
    
    while not pq.empty():
        top = pq.get()
        u = top.id
        w = top.weight

        if(w > dist[u]):continue
        
        for v in graph[u]:
            if w + v.weight < dist[v.id]:
                dist[v.id] = w + v.weight
                pq.put(Edge(dist[v.id], v.id))   

N = int(input())

graph = [[] for _ in range(500 + 5)]
dist = [INF] * (500 + 5)

for _ in range(N):
    a, b, w = map(int, input().split())
    graph[a].append(Edge(w, b))
    graph[b].append(Edge(w, a))
    
s = int(input())
Dijkstra(s)

q = int(input())
for _ in range(q):
    v = int(input())
    if dist[v] != INF:
        print(dist[v])
    else:
        print("NO PATH")