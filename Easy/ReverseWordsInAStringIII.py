class Solution:
    def reverseWords(self, s: str) -> str:
        words=s.split()
        ans=""
        for word in words:
            str="".join(reversed(word))#reversed-returns an Iterator that accesses the given sequence in reverse order
            ans=ans+str+" "
        return ans[:len(ans)-1]#String slicing-does not count the last index
        #join-returns a string concatenated by the Iterable items
        