from queue import Queue # Used for BFS below

"""
    TODO: 
        1. Eventually, incorporate delete? 
        See https://www.freecodecamp.org/news/all-you-need-to-know-about-tree-data-structures-bceacb85490c/
"""

class BST:
    def __init__(self, data:int):
        self.data = data
        self.left = None
        self.right = None

    def Insert(self, val:int) -> None:
        if val <= self.data:
            if self.left == None:
                self.left = BST(val)
            else: self.left.Insert(val)
        else: 
            if self.right == None:
                self.right = BST(val)
            else: self.right.Insert(val)

    def ContainsQ(self, val:int) -> bool:
        if val==self.data:
            return True
        elif val < self.data:
            if self.left == None:
                return False
            else: return self.left.ContainsQ(val)
        else:
            if self.right == None:
                return False
            else: return self.right.ContainsQ(val)

    # All three of the below traversals are examples of depth-first search (DFS)!
    def PrintInOrder(self) -> None:
        if self.left != None:
            self.left.PrintInOrder()
        print(self.data)
        if self.right != None:
            self.right.PrintInOrder()

    def PrintPreOrder(self) -> None:
        print(self.data)
        if self.left != None:
            self.left.PrintInOrder()
        if self.right != None:
            self.right.PrintInOrder()

    def PrintPostOrder(self) -> None:
        if self.left != None:
            self.left.PrintInOrder()
        if self.right != None:
            self.right.PrintInOrder()
        print(self.data)

    # Borrowed from https://www.freecodecamp.org/news/all-you-need-to-know-about-tree-data-structures-bceacb85490c/
    def BFS(self) -> None:
        queue = Queue()
        queue.put(self)

        while not queue.empty():
            current_node = queue.get()
            print(current_node.data)

            if current_node.left:
                queue.put(current_node.left)

            if current_node.right:
                queue.put(current_node.right)

"""
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if not p and not q:
            return True
        elif not p or not q:
            return False
        elif p.val != q.val:
            return False
        else: return self.isSameTree(p.left,q.left) and self.isSameTree(p.right,q.right)
"""

if __name__ == '__main__':
    n1 = BST(50)
    n1.Insert(76)
    n1.Insert(21)
    n1.Insert(4)
    n1.Insert(32)
    n1.Insert(100)
    n1.Insert(64)
    n1.Insert(52)

    n1.PrintInOrder()
    print("\n")

    n1.PrintPreOrder()
    print("\n")

    n1.PrintPostOrder()
    print("\n")

    n1.BFS()
    print("\n")

    print(n1.ContainsQ(8))
    print(n1.ContainsQ(13))
    print(n1.ContainsQ(52))