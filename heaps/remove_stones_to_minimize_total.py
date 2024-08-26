#link: https://leetcode.com/problems/remove-stones-to-minimize-the-total/
import heapq

class Solution:
    def minStoneSum(self, piles: List[int], k: int) -> int:
        piles = [-pile for pile in piles]
        heapq.heapify(piles)
        
        for i in range(k):
            top = abs(heapq.heappop(piles))
            top_half = top //2 
            heapq.heappush(piles, -(top - top_half))
        return -sum(piles)
        
        
