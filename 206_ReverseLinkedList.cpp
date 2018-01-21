/**
206. Reverse Linked List ::
Reverse a singly linked list.
**/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//Version 1 :: Iterative
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head)return head;
        ListNode *prev=nullptr, *curr=head, *next;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return head = prev;
    }
};


//Version 2 :: Recursive
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head)return head;
        function<void(ListNode*)> reverse;
        reverse = [&] (ListNode* node) -> void{
            if(!node->next){
                head = node;
                return;
            }
            reverse(node->next);
            node->next->next = node;
            node->next = nullptr;
        };
        reverse(head);
        return head;
    }
};
