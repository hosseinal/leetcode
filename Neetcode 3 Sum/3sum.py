class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        solutions = []
        results = {}

        # Store index pairs by their sum
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                pair_sum = nums[i] + nums[j]
                results.setdefault(pair_sum, []).append([i, j])

        for i in range(len(nums)):
            target = -nums[i]
            if target in results:
                for a, b in results[target]:
                    if i not in (a, b):
                        triplet = sorted([nums[a], nums[b], nums[i]])
                        if triplet not in solutions:
                            solutions.append(triplet)

        return solutions
