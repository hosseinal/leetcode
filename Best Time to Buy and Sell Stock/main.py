class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        buypoint = 0
        profit = 0
        for i in range(len(prices)):
            diff = prices[i] - prices[buypoint]
            if  diff > 0 and diff > profit:
                profit = diff
            if diff < 0 :
                buypoint = i
        return profit
