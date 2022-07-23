"""
    From https://leetcode.com/explore/learn/card/hash-table/182/practical-applications/1139/
"""

class Bucket:
    def __init__(self):
        self.bucket=[]
    
    def update(self, key:int) -> None:
        found=False
        
        for i,k in enumerate(self.bucket):
            if key==k:
                self.bucket[i]=key
                found=True
                break
                
        if not found:
            self.bucket.append(key)
            
    def contains(self, key:int) -> bool:
        for k in self.bucket:
            if k==key:
                return True
        return False
        
    def remove(self, key:int) -> None:
        for i,k in enumerate(self.bucket):
            if key==k:
                del self.bucket[i]

    def get(self):
        return self.bucket

class MyHashSet:
    def __init__(self):
        self.key_space = 2096
        self.hash_table=[Bucket() for i in range(self.key_space)]
        
    def add(self, key: int) -> None:
        hash_key=key % self.key_space
        self.hash_table[hash_key].update(key)
        
    def remove(self, key: int) -> None:
        hash_key=key % self.key_space
        self.hash_table[hash_key].remove(key)
        
    def contains(self, key: int) -> bool:
        hash_key=key % self.key_space
        return self.hash_table[hash_key].contains(key)

    def print(self) -> None:
        arr = [[i,self.hash_table[i].get()] for i in range(0,self.key_space) if self.hash_table[i].get() != []]
        print(arr)
        
if __name__ == '__main__':  
    obj = MyHashSet()
    obj.print()

    obj.add(2)
    obj.add(2098)
    obj.add(13)
    obj.add(31)
    obj.add(-1)
    obj.print()

    obj.remove(31)
    obj.print()

    param1,param2 = obj.contains(13),obj.contains(31)
    print(param1,param2)
    obj.print()