#leetcode: https://leetcode.com/problems/last-stone-weight/description/
import heapq

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        stones = [-stone for stone in stones]
        heapq.heapify(stones) # turns an array into a heap in linear time
        while len(stones) > 1:
            first = abs(heapq.heappop(stones))
            second = abs(heapq.heappop(stones))
            #if weights are equal they both get destroyed, so we don't have to put anything back into the heap
            if first != second: 
                heapq.heappush(stones, -abs(first - second)) #difference between the 2 max weights in each iteration needs to be positive

        return -stones[0] if stones else 0 #if there is any stone left we return its weight, if there is no stone left we just return 0

#time complexity: O(log(n))
