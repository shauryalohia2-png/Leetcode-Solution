/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        // step 1 - make copy nodes;
        while(temp != nullptr)
        {
            Node* copynode = new Node(temp->val);
            copynode->next = temp->next;
            temp->next = copynode;
            temp = temp->next->next;
        }

        // step 2 - connect random ptr;
        temp = head;
        while(temp != nullptr)
        {
            Node* copynode = temp->next;
            if(!temp->random) 
            copynode->random = nullptr;

            else
            copynode->random = temp->random->next;

            temp = temp->next->next;
        }

        // step 3 - connecct next node;
        temp = head;
        Node* ans = new Node(-1);
        Node* anstemp = ans;
        while(temp != nullptr)
        {
            anstemp->next = temp->next;
            temp->next = anstemp->next->next;
            anstemp = anstemp->next;
            temp = temp->next;
        }
        return ans->next;
    }
};