# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
      
    def rowhelper(self,root,v,d,level):
        if d-1==level:
            lefttree=TreeNode(v,left=root.left)
            righttree=TreeNode(v,right=root.right)
            root.left=lefttree
            root.right=righttree
            return
        
        if root.left:
            self.rowhelper(root.left,v,d,level+1)
        if root.right:
            self.rowhelper(root.right,v,d,level+1)
            
            
    def addOneRow(self, root: Optional[TreeNode], v: int, d: int) -> Optional[TreeNode]:
        if d==1:
            return TreeNode(v,left=root)
        self.rowhelper(root,v,d,1)
        return root
    
  
            
        