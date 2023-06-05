"""
* 그래프 탐색
 - BFS : 너비 탐색
 - DFS : 깊이 탐색
"""

from collections import deque

n, m, v = map(int, input().split())

def BFS(v):
    list = deque(v)
    deque.popleft()
    for i in range(n):
        if visit[v][i] == 0 and graph[v][i] == 1:
            visit[v][i] = 0
    
visit = [ [0]*(n+1) for _ in range(n+1) ]