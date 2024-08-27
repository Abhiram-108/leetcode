class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start: int, end: int) -> float:
        
        adj=collections.defaultdict(list)
        for i in range(len(edges)):
            src,dest=edges[i]
            adj[src].append([dest,succProb[i]])
            adj[dest].append([src,succProb[i]])
            
        pq=[(-1,start)]
        visit=set()
        while pq:
            prob,curr=heapq.heappop(pq)
            visit.add(curr)
            
            if curr==end:
                return prob*-1
            for neigh,edgeprob in adj[curr]:
                if neigh  not in visit:
                    heapq.heappush(pq,(prob*edgeprob,neigh))
        return 0
        