class Solution(object):

    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        # single digit is always true
        if (x % 10 == x):
            return True

        #if neg or ending in zero then false
        if x < 0 or x % 10 == 0:
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
            print("r = {0}".format(r))
            # if r >= x:
            #     break
            r = r + lsd
            if r >= x:
                break
        print("r = {0}, x = {1}".format(r,x))
        if (r == x) or (r//10 == x):
            return True
        return False

if __name__ == '__main__':
    s = Solution()

    d = 1234321
    print('{0} , palindrome = {1}'.format(d, s.isPalindrome(d)))

    d = 123321
    print('{0} , palindrome = {1}'.format(d, s.isPalindrome(d)))

    d = 0
    print('{0} , palindrome = {1}'.format(d, s.isPalindrome(d)))

    d = 9
    print('{0} , palindrome = {1}'.format(d, s.isPalindrome(d)))

    d = 1234567899176
    print('{0} , palindrome = {1}'.format(d, s.isPalindrome(d)))

    d = 1000021
    print('{0} , palindrome = {1}'.format(d, s.isPalindrome(d)))

    d = 10100000000100
    print('{0} , palindrome = {1}'.format(d, s.isPalindrome(d)))

    d = 131000
    print('{0} , palindrome = {1}'.format(d, s.isPalindrome(d)))

    d = 1000030001
    print('{0} , palindrome = {1}'.format(d, s.isPalindrome(d)))
