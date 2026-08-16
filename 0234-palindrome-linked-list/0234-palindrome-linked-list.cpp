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
    bool isPalindrome(ListNode* head) {
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast!=NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode * temp = slow;
        ListNode * prev = NULL;
        while(temp != NULL)
        {
            ListNode * front = temp->next;
            temp->next = prev;
            prev= temp;
            temp= front;
        }
        ListNode * temp1 = prev;
        ListNode * temp2 = head;
        while(temp1!= NULL && temp2!= NULL)
        {
            if(temp1->val!= temp2->val)return false;
            temp1= temp1->next;
            temp2= temp2->next;
        }
        return true;

    }
};