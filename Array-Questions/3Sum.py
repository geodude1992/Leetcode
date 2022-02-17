class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        # return an array
        res = []
        # sort the array
        nums.sort()
        for i, a in enumerate(nums):
            # Not on the first index and current value is not equal to prev
            if i > 0 and a == nums[i - 1]:
                continue
            
            # left and right pointers
            l, r = i + 1, len(nums) - 1
            
            while l < r:
                threeSum = a + nums[l] + nums[r]
                # if sum is greater than 0 move right pointer to the left/decrement
                if threeSum > 0:
                    r -= 1
                # else if sum is less than 0 move Left pointer to the right/increment
                elif threeSum < 0:
                    l += 1
                # else sum = 0
                else:
                    # add to return array
                    res.append([a, nums[l], nums[r]])
                    l += 1
                    # keep incrementing 
                    while nums[l] == nums[l - 1] and l < r:
                        l += 1
        return res
