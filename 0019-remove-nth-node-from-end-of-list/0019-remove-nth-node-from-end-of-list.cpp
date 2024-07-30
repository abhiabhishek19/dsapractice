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
        ListNode* slow = head;
        ListNode* fast = head;
        for(int i=0; i<n; i++)
            fast = fast->next;
        if (fast == nullptr) {
            ListNode* temp = slow->next;
            delete slow;
            return temp;
        }
        while(fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        return head;
    }
};