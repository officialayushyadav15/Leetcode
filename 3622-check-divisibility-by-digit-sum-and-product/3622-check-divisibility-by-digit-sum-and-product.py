class Solution:
    def checkDivisibility(self, n: int) -> bool:
        digitsum = 0
        digitproduct = 1
        num = n
        while num!=0:
            rem = num%10
            digitsum += rem
            digitproduct *= rem
            num = num//10
        return n%(digitsum+digitproduct)==0