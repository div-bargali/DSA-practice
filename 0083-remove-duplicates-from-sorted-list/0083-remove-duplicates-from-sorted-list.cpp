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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* cur = head;
        while(cur) {
            if (cur->next && (cur->val == cur->next->val)) {
                ListNode* tmp = cur;
                while (cur->next && cur->val == cur->next->val)
                    cur = cur->next;
                tmp->next = cur->next;
            }
            cur = cur->next;
        }
        return head;
    }
};