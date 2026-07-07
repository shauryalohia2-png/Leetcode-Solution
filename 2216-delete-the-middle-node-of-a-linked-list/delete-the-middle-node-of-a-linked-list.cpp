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
    ListNode* middle(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* deleteMiddle(ListNode* head) {   
        ListNode* middlenode = middle(head);

        if(head->next == nullptr) 
        {
            return nullptr;
        }

        ListNode* temp = middlenode->next;
        if(temp == nullptr) 
        {
            head->next = nullptr;
            delete middlenode;
            return head;
        }
        middlenode->val = temp->val;
        middlenode->next = temp->next;
        delete temp;

        return head;
    }
};