class Solution:
    def reverse(self, x: int) -> int:
        sign = 1
        
        if x < 0: 
            x*=-1
            sign = -1 
            
        rev = 0
        while x: # while x is not 0
            last = x % 10
            rev = (rev*10) + last
            x = x // 10
        rev*=sign
        return rev if rev > -2**31 and rev < 2**31 - 1 else 0
