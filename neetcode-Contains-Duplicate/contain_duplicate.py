class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        numbers = {}
        for i in nums:
            if i in list(numbers.keys()):
                return True
            else:
                numbers[i] = 1
        
        return False
