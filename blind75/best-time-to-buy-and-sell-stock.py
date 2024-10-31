class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        #find the greatest difference between all values + indices
        #each indice represents a day. 
        #output will be the max profit
        #indice 0 represents day 1

        #stock_profit = []

       # for i in range(len(prices)):
         #   for j in range(i+1, len(prices)):
        #        if prices[i] < prices[j]:
         #           profit = prices[j] - prices[i]
         #           stock_profit.append(profit)

       # return max(stock_profit) if stock_profit else 0

       #above resulted in time limit exceeded. so two pointer solution
        left = 0 #Buy
        right = 1 #Sell
        max_profit = 0
        while right < len(prices):
            currentProfit = prices[right] - prices[left]
            if prices[left] < prices[right]:
                max_profit =max(currentProfit,max_profit)
            else:
                left = right
            right += 1
        return max_profit
