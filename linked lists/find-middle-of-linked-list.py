"""
fast and slow pointer approach: fast will iterate through two nodes at a time while slow pointer will only go through one. by the time the fast pointer reaches the end of the list, the slow pointer will reach halfway through, which will give us the middle of the linked list
"""

def get_middle(head):
    length = 0
    dummy = head
    while dummy:
        length += 1
        dummy = dummy.next
    
    for _ in range(length // 2):
        head = head.next
    
    return head.val
