/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;
        // dummy node.
        ListNode* sumnode = new ListNode(-1);
        ListNode* curr = sumnode;
        
        while(temp1 != nullptr || temp2 != nullptr)
        {
            int sum = 0;
            if(temp1) 
            {
                sum += temp1->val;
                temp1 = temp1->next;
            }
            if(temp2) 
            {
                sum += temp2->val;
                temp2 = temp2->next;
            }
            sum += carry;
            ListNode* next = new ListNode((sum)%10);
            if(sum >= 10)
            {
                carry = 1;
            }
            else if(sum < 10)
            {
                carry = 0;
            }
            curr->next = next;
            
            curr = curr->next;
        }
        if(carry == 1) 
        {
            ListNode* next = new ListNode(carry);
            curr->next = next;
        }
        return (sumnode->next);
    }
};