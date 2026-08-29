class Solution(object):
    def largestOddNumber(self, num):
        """
        :type num: str
        :rtype: str
        """
        n = int(num)
        while n > 0:
            a = n%10
            if a%2 == 1:
                return str(n)
            n //= 10
        return ""