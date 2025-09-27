

def dfs(st):
    s = [st]
    visited[st] = True  
    
    while s:
        u = s.pop()
        
        for v in graph[u]:
            if not visited[v]:
                visited[v] = True
                s.append(v)
                
q = int(input())
for _ in range(q):
    line = ''
    while line == '':
        line = input().strip()
    
    V = int(line)
    E = int(input())
    
    graph = [[] for _ in range(V)]
    visited = [False] * (V + 1)
    
    for i in range (E):
        u, v = map(int, input().split())
        graph[u].append(v)
        graph[v].append(u)
        
    count = 0
    
    for i in range (V):
        if not visited[i]:
            count += 1
            dfs(i)
    print(count) 