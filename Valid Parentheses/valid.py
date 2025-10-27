class Solution:

    def check(self,a,b):
        if a == "(" and b == ")":
            return True
        if a == "[" and b == "]":
            return True
        if a == "{" and b == "}":
            return True
        return False

    def isValid(self, s: str) -> bool:
        stack = []
        if len(s) % 2 == 1:
            return False
        for i in range(len(s)):
            if i in ["}",")","]"] and len(stack) == 0:
                return False
            if s[i] in ["}",")","]"]:
                if stack and self.check(stack[-1], s[i]):
                    stack.pop()
                else:
                    return False
            else:
                stack.append(s[i])
        
        return True if not stack else False
            