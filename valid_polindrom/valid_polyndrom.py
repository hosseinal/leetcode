class Solution:

    def reformatstring(self, s:str) -> str:
        ns = ""
        for i in s:
            if (i >= 'a' and i <= 'z'):
                ns += i
            if (i >='A' and i <= 'Z'):
                ns += i
            if (i >= '0' and i <='9'):
                ns += i
        
        return ns

    def isPalindrome(self, s: str) -> bool:
        
        s = self.reformatstring(s)
        s = s.lower()

        for i in range(len(s)):
            if s[i] != s[len(s) - 1 - i]:
                return False
        
        return True
