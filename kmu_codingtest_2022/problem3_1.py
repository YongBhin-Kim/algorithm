## BFS로 풀면 일부만 맞음
## 비상 연락망

# 6 2 (n, k)
# 0 1
# 2 1
# 1 3
# 4 3
# 4 5

## Use BFS --> 시간 복잡도가 큼
## 반복해서 BFS를 돌려야함, 특히 t값이 클 수록 효율이 떨어짐
## 방문한 edge를 또 방문함
## t = 2 이면 영수, 수지 사이를 많이 돌아다님

import sys
from typing import Deque

def bfs(u, G, t): # t : 단계
    visited = set() # 방문한 애
    q = Deque()
    q.append((u, t)) # 오른쪽에서 넣고
    while len(q) != 0:
        v, vt = q.popleft() # 왼쪽에서 뺌
        visited.add(v)
        if vt > 0:
            for w in graph[v]: # 이웃마다
                if w not in visited:
                    q.append((w, vt - 1)) # w를 넣는데 vt - 1 
    return len(visited)

n, t = map(int, input().split())

graph = [[] for _ in range(n)]
# [
#     [1],
#     [0, 2, 3],
#     [1],
#     [1, 4],
#     [3, 5],
#     [4]
# ]

for line in sys.stdin:
    u, v = map(int, line.split())
    graph[u].append(v)
    graph[v].append(u)

print(max(bfs(u, graph, t) for u in range(n))) # bfs의 최소값


