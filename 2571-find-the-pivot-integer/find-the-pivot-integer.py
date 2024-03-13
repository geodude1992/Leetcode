class Solution:
    def pivotInteger(self, n: int) -> int:
        sum = (n * (n + 1) // 2)
        pivot = int(math.sqrt(sum))
        return pivot if pivot * pivot == sum else -1
        