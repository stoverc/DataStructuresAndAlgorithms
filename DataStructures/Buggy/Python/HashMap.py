"""
    From https://leetcode.com/explore/learn/card/hash-table/182/practical-applications/1140/
"""

class Bucket:
    def __init__(self):
        self.bucket=[]
    
    def update(self, key:int, val:int) -> None:
        found=False
        
        for i,k in enumerate(self.bucket):
            if key==k[0]:
                self.bucket[i]=[key,val]
                found=True
                break

        if not found:
            self.bucket.append([key,val])
            
    def containsKey(self, key:int) -> bool:
        for k in self.bucket:
            if k[0]==key:
                return True
        return False
    
    def containsPair(self, key:int, val:int) -> bool:
        for k in self.bucket:
            if k[0]==key and k[1]==val:
                return True
        return False
        
    def remove(self, key:int) -> None:
        for i,k in enumerate(self.bucket):
            if key==k[0]:
                del self.bucket[i]

    def get(self):
        return self.bucket

class MyHashMap:
    def __init__(self):
        self.key_space = 2096
        self.hash_table=[Bucket() for i in range(self.key_space)]
        print(self.print())
    
    def put(self, key:int, val:int) -> None:
        hash_key=key % self.key_space
        self.hash_table[hash_key].update(key,val)
        print(self.print())
    
    def get(self, key:int) -> int:
        hash_key=key % self.key_space
        
        if not self.hash_table[hash_key].containsKey(key):
            return -1
        else: return self.hash_table[hash_key].bucket[0][1]

    def remove(self, key: int) -> None:
        hash_key=key % self.key_space
        self.hash_table[hash_key].remove(key)
        print(self.print())

    def print(self) -> str:
        arr = [self.hash_table[i].get()[0] for i in range(0,self.key_space) if self.hash_table[i].get() != []]
        
        return(str(arr))
        
if __name__ == '__main__': 
    ob = MyHashMap()
    ob.put(1, 1)
    ob.put(2, 2)
    #print(ob.get(1))
    #print(ob.get(3))
    ob.put(2, 1)
    #print(ob.get(2))
    ob.remove(2)
    #print(ob.get(2))
    ob.put(2098,3)