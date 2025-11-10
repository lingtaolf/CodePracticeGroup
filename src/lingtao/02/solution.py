from typing import Optional
# Definition for singly-linked list.
class ListNode:
     def __init__(self, val=0, next=None):
         self.val = val
         self.next = next

def print_list(l: Optional[ListNode]):
    print("=======")
    while(l):
        print(l.val)
        l = l.next

class Solution:
    @classmethod
    def addTwoNumbers(cls, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        #假设两个长度相同
        res = None
        cur_res_node = None
        flag = 0

        while(l1 or l2):
            l1_val = l1.val if l1 else 0
            l2_val = l2.val if l2 else 0

            cur_res_val = (l1_val + l2_val + flag) % 10
            flag = (l1_val + l2_val + flag) // 10

            if res:
                cur_res_node.next = ListNode(cur_res_val) 
                cur_res_node = cur_res_node.next
            else:
                res = ListNode(cur_res_val)
                cur_res_node = res

            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None

        if flag > 0:
            cur_res_node.next = ListNode(flag)

        return res

if __name__ == '__main__':
    l1 = ListNode(2, ListNode(4, ListNode(3)))
    l2 = ListNode(5, ListNode(6, ListNode(4)))
    print_list(Solution.addTwoNumbers(l1, l2))




