class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        #dfs + backtracking to genearte all the paths
        #1. build the graph
        #vertex, map all the vertexes you can reach
        #traverse the graph and build all paths using backtracking
        
        self.graph = collections.defaultdict(list)
        
        for i, edges in enumerate(graph): #i = node. first, we have to start off by creading the hashMap that we will start iterating over
            self.graph[i] = edges 
        res = [] #initialize res variable as usial
            
        def dfs(cur_path, cur_node): #our backtracking function
            if cur_node == len(self.graph) - 1:
                res.append(list(cur_path))
            
            for connection in self.graph[cur_node]: #similar to the letter combinations, accessing connections of each node
                cur_path.append(connection) #append connection
                dfs(cur_path, connection) #backtrack to next node
                cur_path.pop() #start clean on next iteration
        dfs([0], 0) #call function
        return res #return result
            
