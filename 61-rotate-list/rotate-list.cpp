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
    ListNode* reverse(ListNode* newhead)
    {
        ListNode* curr = newhead;
        ListNode* prev = nullptr;
        while(curr != nullptr)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    int length(ListNode* head)
    {
        int i=0;
        ListNode* curr = head;
        while(curr != nullptr)
        {
            i++;
            curr = curr->next;
        }
        return i;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int l = length(head);
        if(l==0) return nullptr;
        k = k%l;
        for(int i=0 ; i<k ; i++)
        {
            ListNode* newhead = reverse(head);
            ListNode* nextnode = reverse(newhead->next);
            newhead->next = nextnode;
            head = newhead;
        }
        return head;
    }
};