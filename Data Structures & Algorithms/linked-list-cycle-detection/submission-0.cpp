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
    bool hasCycle(ListNode* head) {
        ListNode* tortoise = head;
        ListNode* rabbit = head;

        while (rabbit != nullptr && rabbit->next != nullptr) {
            rabbit = rabbit->next->next;
            tortoise = tortoise->next;

            if (tortoise == rabbit) return true;
        }

        return false;
    }
};
