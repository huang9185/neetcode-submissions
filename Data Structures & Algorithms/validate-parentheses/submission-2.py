class Solution:
    def isOpen(self, c: str) -> bool:
        return c in ['(','[','{']
    def close(self, c:str) -> str:
        if c == ')':
            return '('
        elif c == ']':
            return '['
        elif c == '}':
            return '{'
        else:
            return "Else"

    def isValid(self, s: str) -> bool:
        l = []
        for i in s:
            if self.isOpen(i):
                l.append(i)
                continue
            
            if len(l) and self.close(i) == l.pop():
                pass
            else:
                return False

        if len(l):
            return False

        return True
