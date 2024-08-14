class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        matching = {"(": ")", "[": "]", "{": "}"}
        
        for c in s:
            if c in matching: # if c is an opening bracket
                stack.append(c)
            else:
                if not stack: #implies that we start with miscellanious character or closed parentheses
                    return False
                
                previous_opening = stack.pop()
                if matching[previous_opening] != c: #checks if the top of the stack's key is not equal to c
                    return False
 
        return not stack
