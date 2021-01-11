Copy List with Random Pointer
Medium

4392

780

Add to List

Share
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

The Linked List is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) where random pointer points to, or null if it does not point to any node.
 

Example 1:


Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
Example 2:


Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
Example 3:



Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
Example 4:

Input: head = []
Output: []
Explanation: Given linked list is empty (null pointer), so return null.
 

Constraints:

-10000 <= Node.val <= 10000
Node.random is null or pointing to a node in the linked list.
The number of nodes will not exceed 1000.



Solution:



class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return head;
        Node*iter=head,*front=head;
        
        while(iter!=NULL)
        {
            //1.front will be iter->next
            front=iter->next;
            //2.create a copy node
            Node* copy=new Node(iter->val);
            iter->next=copy;
            copy->next=front;
            iter=front;
        }
        
        iter=head;
        while (iter) 
    { 
        if(iter->next) 
            iter->next->random = iter->random ?  
                                 iter->random->next : iter->random; 
  
        // move to the next newly added node by 
        // skipping an original node 
        iter = iter->next?iter->next->next:iter->next; 
    } 
    Node* original = head, *copy = head->next; 
  
    // save the start of copied linked list 
    Node* temp = copy; 
  
    // now separate the original list and copied list 
    while (original && copy) 
    { 
        original->next = 
         original->next? copy->next->next : original->next; 
  
        copy->next = copy->next?copy->next->next:copy->next; 
        original = original->next; 
        copy = copy->next; 
    } 
  
    return temp; 
        
    }
};
