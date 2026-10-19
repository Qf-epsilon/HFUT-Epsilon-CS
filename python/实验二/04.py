class ListNode:
    def __init__(self, val: int = 0, next=None):
        self.val = val
        self.next = next

def reverseList(head):
    prev = None
    curr = head
    while curr != None:
        next_node = curr.next
        curr.next = prev
        prev = curr
        curr = next_node
    return prev

head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
new_head = reverseList(head)

res = []
curr = new_head
while curr:
    res.append(str(curr.val))
    curr = curr.next

print("反转后的链表为:", " -> ".join(res))