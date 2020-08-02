class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join(reversed(s.split()))
        #reversed-returns an Iterator that accesses the given sequence in reverse order
        #join-returns a string concatenated with the iterable items