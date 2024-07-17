from collections import defaultdict, deque

def pode_visitar_k_cidades(time_limit, graph, N, K):
    visited = [False] * (N + 1)
    queue = deque([1])
    visited[1] = True
    count = 1
    
    while queue:
        node = queue.popleft()
        for neighbor in graph[node]:
            if not visited[neighbor]:
                visited[neighbor] = True
                queue.append(neighbor)
                count += 1
                if count >= K:
                    return True
    return False

def minimas_horas_para_visitar_k_cidades(N, M, K, edges):
    edges.sort(key=lambda x: x[2])  
    left, right = 0, edges[-1][2]
    result = right
    
    while left <= right:
        mid = (left + right) // 2
        
        graph = defaultdict(list)
        for u, v, c in edges:
            if c <= mid:
                graph[u].append(v)
                graph[v].append(u)
        
        if can_visit_k_cities(mid, graph, N, K):
            result = mid
            right = mid - 1
        else:
            left = mid + 1
    
    return result

N, M, K = map(int, input().split())
edges = [tuple(map(int, input().split())) for _ in range(M)]

print(minimum_hours_to_visit_k_cities(N, M, K, edges))