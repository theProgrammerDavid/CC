# https://leetcode.com/problems/valid-palindrome-ii/
class Solution:
    def checkPal(self, s:str, start, end)->bool:
        while start < end:
            if s[start] != s[end]:
                return False
            start+=1
            end-=1
        return True
            
    def validPalindrome(self, s: str) -> bool:
        i=0
        j = len(s)-1
        
        while(i<j):
            if s[i] != s[j]:
                return self.checkPal(s,i+1,j) or self.checkPal(s,i,j-1)
            i+=1
            j-=1
        return True
            
        