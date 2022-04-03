class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        # count
        # Time O(n^2) Space O(1)
        
        # Sort and i, i+1
        # Time O(nlogn) Space O(1)
        """
        nums.sort()
        for i in range(len(nums)-1):
            if nums[i] == nums[i+1]:
                return True
        return False
        """
        
        # Save each element in hashset and check
        # Time O(n) Space O(n)
        hashset = set()
        for element in nums:
            if element in hashset:
                return True
            hashset.add(element)
        return False
        
