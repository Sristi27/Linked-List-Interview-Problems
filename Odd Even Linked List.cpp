Odd Even Linked List
Medium

2657

329

Add to List

Share
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL
Example 2:

Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL
 

Constraints:

The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...
The length of the linked list is between [0, 10^4].


brute force: take another head and 2 queues for storing odd and even nodes.Then pop accordingly and keep adding to new temporary head. 

Solution

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL) return head;
        ListNode*odd=head,*even=head->next;
        ListNode* first=even;
        while(1)
        {
            //no more odd or even
            if(!odd || !even || !(even->next))
            {
                odd->next=first;
                break;
            }
            
            //odd nodes connection
            odd->next=even->next;
            odd=even->next;
            
            
            //no more even nodes
            if(odd->next==NULL)
            {
                even->next=NULL;
                odd->next=first;
                break;
            }
            
            
            //even connection
            even->next=odd->next;
            even=odd->next;
            
        }
        return head;
    }
};
