class Solution:
    def partitionString(self, s: str) -> int:
        currset=set()

        res=0;

        for c in s:
            if c in currset:
                res=res+1
                currset=set()
                currset.add(c)
            else:
                currset.add(c)
            
        return res+1
            