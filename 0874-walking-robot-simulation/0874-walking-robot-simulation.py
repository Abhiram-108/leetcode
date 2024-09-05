class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        directions=[(0,1),(1,0),(0,-1),(-1,0)]
        current=0
        max_distance=0
        obj=set()
        for x,y in obstacles:
            obj.add((x,y))
        x,y=0,0
        for c in commands:
            if c==-2:
                current=(current+3)%4
            if c==-1:
                current=(current+1)%4
            else:
                dx,dy=directions[current]
                for _ in range(c):
                    nx,ny=x+dx,y+dy
                    if(nx,ny) in  obj:
                        break
                    x,y=nx,ny
                    max_distance=max(max_distance,x*x+y*y)
        return max_distance