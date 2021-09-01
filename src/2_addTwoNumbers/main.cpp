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
        ListNode* result = new ListNode();
        int carray = 0;

        int total_value = l1->val + l2->val;
        if (total_value>=10){
            result->val = total_value%10;
            carray = 1;
        }
        else
            result->val = total_value;

        if(l1->next && l2->next){
            l1->next->val += carray;
            carray = 0;
            result->next = addTwoNumbers(l1->next, l2->next);
        }
        
        else if(!l1->next && !l2->next){
           if (carray)
               result->next = new ListNode(1);
            return result; 
       }

        else if (!l1->next){
            result->next = addTwoNumbers(new ListNode(carray), l2->next);
            return result;
        }

        else if (!l2->next){
            result->next = addTwoNumbers(l1->next, new ListNode(carray));
            return result;
        }
        
        return result;

            
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