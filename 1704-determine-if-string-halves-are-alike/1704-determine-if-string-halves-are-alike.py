class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        count1 = 0
        count2 = 0
        for i in range(0, len(s) // 2):
            if s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u' or s[i] == 'A' or s[i] == 'E' or s[i] == 'I' or s[i] == 'O' or s[i] == 'U':
                count1 = count1 + 1
        for i in range(len(s) // 2, len(s)):
            if s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u' or s[i] == 'A' or s[i] == 'E' or s[i] == 'I' or s[i] == 'O' or s[i] == 'U':
                count2 = count2 + 1;
        return count1 == count2
    
        