## Use DP
## T = 뻗어나갈 수 있는 노드의 개수
import sys
n, t = map(int, input().split())

graph = [[] for _ in range(n)]


for line in sys.stdin:
    u, v = map(int, line.split())
    graph[u].append(v)
    graph[v].append(u)
    
T = [[1] for _ in range(n)]
# T[u][0] = 1
# T[u][1] = 1 + len(graph(u))

for u in range(n):
    T[u].append(1 + len(graph[u]))
    
for k in range(2, t+1):
    for u in range(n):
        x = -T[u][k-2] * (len(graph[u]) - 1)
        for v in graph[u]:
            x += T[v][k-1]
        T[u].append(x)

ans = max(T[u][t] for u in range(n))
print(ans)


## 3번 째 방법
## bi-directed graph
