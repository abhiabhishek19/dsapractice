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
private:
    int len(ListNode* head)
    {
        ListNode* temp=head;
        int c=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            c++;
        }
        return c;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL )
        {
            return head;
        }
        int l=len(head);
        int r=l-n;
        if (r == 0) {
            ListNode* temp = head;
            head = head->next;
            return head;
        }
        ListNode* p=NULL;
        ListNode* curr =head;
        int ct=0;
        while(curr->next!=NULL && ct<r)
        {
            p=curr;
            curr=curr->next;
            ct++;
        }
        if(curr->next==NULL)
            p->next=NULL;
        else
            p->next=curr->next;
        return head;
    }
};