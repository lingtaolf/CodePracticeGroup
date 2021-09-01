#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carray = 0;

        if ((l1->val + l2->val)>=10){
            l1->val = (l1->val + l2->val)%10;
            carray = 1;
        }
        else
            l1->val = l1->val + l2->val;

        if(l1->next || l2->next){
            if (l1->next){
                l1->next->val += carray;
                l1->next = addTwoNumbers(l1->next, l2->next? l2->next: new ListNode(0));
            }
            else if (l2->next){
                l2->next->val += carray;
                l1->next = addTwoNumbers(l1->next? l1->next: new ListNode(0), l2->next);
            }
            carray = 0;
        }
        
        else {
           if (carray)
               l1->next = new ListNode(1);
       }
        
        return l1;

    }
  

 };

void print(ListNode* l){
    if (l)
    {
        std::cout<<l->val;
        print(l->next);
    }
}

int main() {
    ListNode l1(9, new ListNode(9, new ListNode(9)));
    ListNode l2(9, new ListNode(9));
    
    Solution s;
    ListNode* res = s.addTwoNumbers(&l1, &l2);

    print(res); 
    return 0;
}