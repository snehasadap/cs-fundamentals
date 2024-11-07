class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        #graph will have depth of len(digits)
        if len(digits) == 0:
            return []
        
        letters = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz",
        }

        def backtrack(i, curr): #index of original string = i
            if len(curr) == len(digits):
                ans.append("".join(curr)) #append the length
                return
            
            possible_letters = letters[digits[i]] #get all the possible digits of the current index
            
            for letter in possible_letters: #iterates through letters of the curr index in the origjnal string
                curr.append(letter)
                backtrack(i+1, curr) #append next letter of next value
                curr.pop()
        ans = []
        backtrack(0, [])
        return ans
            
            
        
