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
    void insertattail(ListNode* &head, ListNode* &tail, int value) {
        ListNode* temp = new ListNode(value);
        if (head == NULL) {
            head = temp;
            tail = temp;
            return;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* ansh = NULL;
        ListNode* anst = NULL;
        while (l1 != NULL || l2 != NULL || carry != 0) {
            int val1=0;
            if(l1!=NULL)
            {
                val1=l1->val ;
            }
            int val2=0;
            if(l2!=NULL)
            {
                val2=l2->val ;
            }
            int sum = val1+ carry + val2;
            int digit = sum % 10;
            

            insertattail(ansh, anst, digit);
            carry = sum / 10;
            if(l1!=NULL)
            {
                l1 = l1->next;
            }
            if(l2!=NULL)
            {
                l2 = l2->next;
            }
            
        }
        return ansh;
    }
};