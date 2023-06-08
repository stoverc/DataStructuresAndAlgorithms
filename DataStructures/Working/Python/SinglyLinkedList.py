"""
    From https://leetcode.com/explore/learn/card/linked-list/209/singly-linked-list/1290/.
    Some elements were based on https://stackoverflow.com/questions/68974018/insert-at-index-in-linked-list, though
    that code + the code in the accepted comment contained >= 2 very serious bugs + needed quite a bit of plussing
    up to reach the level of "accepted LeetCode answer."
"""
# Nodes contain a data element and a "pointer" to the next element.
class Node:
    def __init__(self,data):
        self.data = data
        self.next = None

# LinkedList has a well-defined head.
class MyLinkedList:
    def __init__(self):
        self.head = None
    
    # Make existing head the second element and make a blank node the first.
    def addAtHead(self, val) -> None:
        new_node = Node(val)                        # New node; to be new head
        new_node.next = self.head                   # Make the old head the second node
        self.head = new_node                        # Make the new node the head

    # Make existing tail the next-to-last element and make the given node the tail.
    def addAtTail(self, val) -> None:
        new_node = Node(val)                        # New node; to be new tail

        if(self.head == None):                      # If list has no head,...
            self.head = new_node                    # ...then tail = head = new node.
        else:
            curr = self.head                        # If not, then start with the head...
            while curr.next is not None:            # ...cycle through all the nodes until you hit the last node (whose next = None)...
                curr = curr.next                    # ...setting the current node as the next node at each iteration...
            curr.next = new_node                    # ...and when the loop stops (on the last node), set the next node to be the new node.

    # Make existing (index)th node the (index+1)th and make make the given node the (index)th.
    def addAtIndex(self, index:int, val:int) -> None:
        new_node = Node(val)                        # New node; to be new (index)th

        if index < 0 or index >= self.length():     # index < 0 or index >= self.length() are both invalid, so...
            pass                                    # ...we pass.

        if index == 0:                              # Inserting at index = 0 is the same as inserting at the head...
            self.addAtHead(val)                     # ...so we use our built-in method.

        count = 0                                   # Begin a counter...
        curr = self.head                            # ...and start with curr equal to the head.
        while curr is not None:                     # As long as we haven't hit the last node...
            if count == index-1:                    # ...check to see if we're at the desired location's predecessor. If so...
                new_node.next = curr.next           # ...make the blank node's next copy the current node's next...
                curr.next = new_node                # ...and make the current node's next equal the new node. Finally...
                break                               # ...stop looping.
            curr = curr.next                        # If not, then progress to the next node...
            count+=1                                # ...and update the counter.

    # Though not strictly necessary for a linked list, this is useful for other linked list functions.
    def length(self) -> int:
        size = 0                                    # Begin a counter...
        curr = self.head                            # ...and start with curr equal to the head.
        while curr is not None:                     # As long as we haven't hit the last node...
            size+=1                                 # ...increment the counter...
            curr = curr.next                        # ...and move on to the next node.

        return size                                 # Return the counter.

    # Delete existing (index)th node and make the current (index+1)th the the new (index)th.
    def deleteAtIndex(self, index:int) -> None:
        temp = self.head                            # Start by tracking the head.
        i = 0                                       # Begin a counter.
 
        if (temp is not None):                      # As long as the list has >= 1 element...
            if (i == index):                        # ...check to see whether 0 is at the right spot, and if so...
                self.head = temp.next               # ...we're deleting the head. This means reassign the head to temp's next...
                return                              # ...and we're done! If not...
 
        # Search for the key to be deleted, keep track of the previous node as we need to change 'prev.next'
        while(temp is not None):                    # ...iterate through the nodes in the list.
            if i == index:                          # If you're at the right index,...
                break                               # ...stop iterating.
            i += 1                                  # Otherwise, increase the counter...
            prev = temp                             # ...track the previous node as current "temp"...
            temp = temp.next                        # ...and increment "temp" to be the next node.
 
        if(temp == None):                           # If key was not present in linked list...
            return                                  # ...do nothing.

        prev.next = temp.next                       # Now, make new (index)th node's next node equal to the temp var's next node.
    
    # Return the data stored at a particular index.
    def get(self, index: int) -> int:
        count = 0                                   # Begin a counter...
        curr = self.head                            # ...and start with curr equal to the head.

        if index == 0 and self.head != None:        # If the user asks for the 0th entry and the list has > 0 entries...
            return self.head.data                   # ...return the 0th entry's data...
        else:                                       # ...otherwise...
            while curr is not None:                 # ...iterate through the nodes.
                if count == index:                  # If you've reached the desired index...
                    return curr.data                # ...return the correponding data. If not...
                curr = curr.next                    # ...move on to the next node...
                count+=1                            # ...and increment the counter.

        return -1                                   # If you haven't already returned a value, then the value must be -1 as the node does not exist.
    
    # Print an array of all the values in the current list
    def print(self) -> None:
        temparr = []                                # Initialize an empty list (to hold the values)...
        curr = self.head                            # ...and start with curr equal to the head.

        while curr is not None:                     # As long as we haven't hit the last node...
            temparr.append(curr.data)               # ...add the node's value to the end of the array...
            curr = curr.next                        # ...and move on to the enxt node.
        
        print(temparr)                              # Print the array when finished.
              
if __name__ == '__main__':  
    obj = MyLinkedList()
    obj.print()

    obj.addAtTail(1)
    obj.print()

    print(obj.get(0))

    obj.addAtHead(1)
    obj.print()

    obj.addAtTail(3)
    obj.print()

    obj.addAtIndex(1,2)
    obj.print()

    obj.addAtTail(3)
    obj.print()

    obj.addAtIndex(1,2)
    obj.print()

    print(obj.get(1))

    obj.deleteAtIndex(1)
    obj.print()

    print(obj.get(1))

    print(obj.get(4))
    obj.addAtTail(85)
    obj.print()
    