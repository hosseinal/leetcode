class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        elements = {}

        for c in s:
            elements[c] = elements.get(c, 0) + 1

        for c in t:
            if c not in elements or elements[c] == 0:
                return False
            elements[c] -= 1

        return True
