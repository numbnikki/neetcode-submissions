class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        subset = []
        ans = []

        def dfs(index):
            if index >= len(nums):
                ans.append(subset.copy())
                return
            subset.append(nums[index])
            dfs(index + 1)
            subset.pop()
            dfs(index + 1)

        dfs(0)
        return ans
