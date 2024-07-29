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
    // void Solve(ListNode* &head, ListNode* prev,ListNode* curr )
    // {
    //     if(curr==NULL)
    //     {
    //         head=prev;
    //         return;
    //     }
    //     ListNode* forward = curr->next;
    //     Solve(head,curr,forward);
    //     curr->next = prev;
    // }
    private:
    ListNode* Solve2(ListNode* &head)
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode* subhead=Solve2(head->next);
        head->next->next=head;
        head->next=NULL;
        return subhead;
    }
public:
    ListNode* reverseList(ListNode* head) {
        // ListNode* curr = head;
        // ListNode* prev = NULL;
        // Solve(head,prev,curr);
        return Solve2(head);
        
        // ListNode* forward = NULL;
        // if(head==NULL || head->next==NULL)
        // {
        //     return head;
        // }
        // while(curr!=NULL)
        // {
        //     forward=curr->next;
        //     curr->next=prev;
        //     prev=curr;
        //     curr=forward;
            
        // }
        // return prev;
        
    }
};