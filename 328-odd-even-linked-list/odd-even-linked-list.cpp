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
        ListNode* odd = head2;
        ListNode* even = head1;
        head2->next = odd->next;
        head1->next = odd;
        while(odd != nullptr && odd->next != nullptr && even != nullptr && even->next != nullptr)
        {
            even->next = odd->next;
            if(even->next != nullptr) even = even->next;
            odd->next = even->next;
            if(odd->next != nullptr) odd = odd->next;
            
        }
        even->next = head2;
        return head1;
    }
};