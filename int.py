class Solution(object):
    
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
       # print(s)
        if len(s)==1:
            return s
        l=""+s[0]
        
'''        for i in range(1,len(s)-1):
            p1,p2=i-1,i+1
            while p1>=0 and p2<=len(s)-1:
                if s[p1]==s[p2]:
                    if p2-p1+1>len(l):
                        l=s[p1:p2+1]
                    p1-=1
                    p2+=1
                else:
                    break           '''
                    
        for i in range(0,len(s)-1):
            if s[i]==s[i+1]:
                if len(l)<2:
                    l=s[i:i+2]
                p1,p2=i-1,i+2
                
                while p1>=0 and p2<=len(s)-1:
                    if s[p1]==s[p2] and len(l)<p2-p1+1:
                        l=s[p1:p2+1]
                        p1-=1
                        p2+=1
                    else:
                        break
            print(i,l)            
                
        
        return l