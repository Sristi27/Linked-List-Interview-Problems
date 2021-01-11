You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]
Example 2:

Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]
Example 3:

Input: head = [1], k = 1
Output: [1]
Example 4:

Input: head = [1,2], k = 1
Output: [2,1]
Example 5:

Input: head = [1,2,3], k = 2
Output: [1,2,3]
 

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 105
0 <= Node.val <= 100





Solution




class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==NULL) return head;
        ListNode* root=head,*root1=head;
        int first,second;
        int len=0;
        while(root!=NULL)
        {
            len++;
            if(len==k)
            {   
                first=root->val;
                break;
            }
            root=root->next;
            
        }
        ListNode*slow=head,*fast=head;
        
        for(int i=0;i<k;i++)
        {
            fast=fast->next;
        }
        
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        
        if(fast==NULL)
        {
            second=slow->val;
            slow->val=first;
        }
        else
        {
            if(slow->next)
            {
                second=slow->next->val;
                slow->next->val=first;
            }
            else
            {
                second=slow->val;
                slow->val=first;
            }
        }
        
        root=head;
        len=0;
        while(root!=NULL)
        {
            len++;
            if(len==k)
            {   
                root->val=second;
                break;
            }
            root=root->next;
            
        }
        return head;
    }
};

