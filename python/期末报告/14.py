class Node:
    def __init__(self,data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def append(self,val):
        new_node = Node(val)
        if self.head is None:
            self.head = new_node
            return
        cur = self.head
        while cur.next is not None:
            cur = cur.next
        cur.next = new_node

    def traverse(self):
        cur = self.head
        while cur is not None:
            print(cur.data,end=" ")
            cur = cur.next
        print()

ll = LinkedList()
ll.append(10)
ll.append(20)
ll.append(30)
ll.traverse()