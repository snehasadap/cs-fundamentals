#link: https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/description/
class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        graph = collections.defaultdict(list)
        for x, y in edges:
            graph[x].append(y)
            graph[y].append(x)
        
        def dfs(node, seen):
            seen.add(node)
            for neighbor in graph[node]:
                if neighbor not in seen:
                    dfs(neighbor, seen)
        count = 0
        seen = set()
        for node in range(n):
            if node not in seen:
                dfs(node, seen)
                count += 1
        return count
        
