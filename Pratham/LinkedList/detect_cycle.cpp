/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//  https://leetcode.com/problems/linked-list-cycle/submissions/

class Solution {
public:
    bool hasCycle(ListNode *head) {

        ListNode *slow, *fast;

        if(!head){
                return false;
        }

        slow = head;
        fast = head->next;

        while(fast != NULL && fast->next != NULL){c
            if(slow == fast){
                return true;
            }

            fast = fast->next->next;
            slow = slow->next;
        }

        return false;
    }
};
