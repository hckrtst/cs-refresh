
class Solution(object):
    # def extract_msd(self, x):
    #     old_x = x
    #     count = 0
    #     while (x // 10) is not 0:
    #         x = x // 10
    #         count += 1
    #     print('x = {0}, count = {1}'.format(x, count))
    #     res = old_x - (x * (10**count))
    #     return (res, x)
    #
    # Fails if there are zeros! ex: 100021
    # def isPalindrome(self, x):
    #     """
    #     :type x: int
    #     :rtype: bool
    #     """
    #     if x < 0:
    #         return False
    #     # if only single digit
    #     if x < 10:
    #         return True
    #     old_x = x
    #     x = old_x // 10
    #     lsd = old_x - (x*10)
    #     x, msd = self.extract_msd(x)
    #     print('lsd = {0} msd = {1}'.format(lsd ,msd))
    #     if msd != lsd:
    #         return False
    #     return self.isPalindrome(x)
    def rev(self, x):
        pass
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False

        r = 0
        while (r < x):
            lsd = x % 10
            if (x//10) is 0:
                break
            x = x // 10
            # if r >= x:
            #     break
            r = r * 10
            if r >= x:
                break
            r = r + lsd
            if r >= x:
                break

        if (r == x) or (10*x == r):
            return True
        return False

if __name__ == '__main__':
    s = Solution()
    s.isPalindrome(45321)
    d = 1234321
    print('{0} , palindrome = {1}'.format(d, s.isPalindrome(d)))
    #s.isPalindrome(4568654)
    d = 123321
    print('{0} , palindrome = {1}'.format(d, s.isPalindrome(d)))

    d = 0
    print('{0} , palindrome = {1}'.format(d, s.isPalindrome(d)))
    d = 1234567899176
    print('{0} , palindrome = {1}'.format(d, s.isPalindrome(d)))

    d = 1000021
    print('{0} , palindrome = {1}'.format(d, s.isPalindrome(d)))

    d = 10100000000100
    print('{0} , palindrome = {1}'.format(d, s.isPalindrome(d)))
