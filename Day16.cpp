/* Odd Even Linked List

Given a singly linked list, 
group all odd nodes together followed by the even nodes. 
Please note here we are talking about the node number and not the value in the nodes.
You should try to do it in place. 
The program should run in O(1) space complexity and O(nodes) time complexity.*/

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
        if(head == nullptr) return head;
        ListNode* odd= head;
        ListNode* evenHead = odd->next;
        ListNode* even = odd->next;
        while(even!=nullptr && even->next!=nullptr){
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};