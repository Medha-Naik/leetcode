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

    ListNode * reversell(ListNode * head)
    {
        ListNode * nextNode;
        ListNode * prev=NULL;
        ListNode *temp=head;
        if(temp==NULL||temp->next==NULL)return temp;
        while(temp!=NULL)
        {
            nextNode=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nextNode;
        }
        return prev;

    }
    ListNode* getkthNode(ListNode * head,int k)
    {
        ListNode * temp=head;
        k--;
        while(temp!=NULL&&k>0)
        {
            temp=temp->next;
            k--;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * temp=head;
        ListNode * prevlast=NULL;
        while(temp != NULL) {
    ListNode* kthnode = getkthNode(temp, k);

    if(kthnode == NULL) {
        if(prevlast) prevlast->next = temp;
        break;
    }

    ListNode* nextnode = kthnode->next; 
    kthnode->next = NULL;               

    ListNode* newhead = reversell(temp);

    if(temp == head) {
        head = newhead;
    } else {
        prevlast->next = newhead;
    }

    prevlast = temp;
    temp = nextnode; 
}
        return head;
    }
};