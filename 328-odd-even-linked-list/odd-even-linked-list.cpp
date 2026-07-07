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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* head2 = head->next;
        ListNode* head1 = head;
        ListNode* even = head2;
        ListNode* odd = head1;
        
        while(odd != nullptr && odd->next != nullptr && even != nullptr && even->next != nullptr)
        {
            odd->next = even->next;
            if(odd->next != nullptr) odd = odd->next;
            
            even->next = odd->next;
            if(even->next != nullptr) even = even->next;
        }
        odd->next = head2;
        return head1;
    }
};