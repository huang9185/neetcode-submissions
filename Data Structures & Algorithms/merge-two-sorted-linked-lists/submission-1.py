# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        h1 = list1
        h2 = list2
        if not (h1 or h2):
            return None
        elif not h2:
            head = h1
            h1 = h1.next
        elif not h1:
            head = h2
            h2 = h2.next
        elif h1.val < h2.val:
            head = h1
            h1 = h1.next
        elif h1.val >= h2.val:
            head = h2
            h2 = h2.next
        

        begin = head
        while h1 or h2:
            if not h2 or (h1 and h2 and h1.val < h2.val):
                head.next = h1
                h1 = h1.next
                head = head.next
            elif (h1 and h2 and h1.val >= h2.val) or not h1:
                head.next = h2
                h2 = h2.next
                head = head.next

        return begin