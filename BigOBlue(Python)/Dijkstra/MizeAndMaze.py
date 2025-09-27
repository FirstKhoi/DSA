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
        w = top.weight
        u = top.id
        if(w > dist[u]): 
            continue
        for v in graph[u]:
            if w + v.weight < dist[v.id]:
                dist[v.id] = w + v.weight
                pq.put(Edge(dist[v.id], v.id))
                
n = int(input())
graph = [[] for _ in range(n + 1)]
dist = [INF] * (n + 1)
e = int(input()) 
t = int(input())
m = int(input())
for _ in range(m):
    u, v, w = map(int, input().split())
    graph[v].append(Edge(w, u))
        
Dijkstra(e)
count = 0
for i in range(1, n + 1):
    if dist[i] <= t:
        count += 1
print(count)