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
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while(curr != nullptr)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* newhead = reverse(head);
        ListNode* curr = newhead;
        ListNode* prev = nullptr;
        if(n==1)
        {
            newhead = curr->next;
            delete curr;
            return reverse(newhead);
        }
        
        for(int i=1 ; i<n ; i++)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        delete curr;

        return reverse(newhead);
    }
};