Merge Two Sorted Lists
Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.

 

Example 1:


Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: l1 = [], l2 = []
Output: []
Example 3:

Input: l1 = [], l2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both l1 and l2 are sorted in non-decreasing order.





C++	
1
/**
2
 * Definition for singly-linked list.
3
 * struct ListNode {
4
 *     int val;
5
 *     ListNode *next;
6
 *     ListNode() : val(0), next(nullptr) {}
7
 *     ListNode(int x) : val(x), next(nullptr) {}
8
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9
 * };
10
 */
11
class Solution {
12
public:
13
    struct compare
14
    {
15
        bool operator()(struct ListNode *a,struct ListNode *b)
16
        {
17
            return a->val>b->val;
18
        }
19
    };
20
    
21
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
22
        if(!l1 && !l2) return NULL;
23
        if(l1 && !l2) return l1;
24
        if(!l1 && l2) return l2;
25
        
26
        priority_queue<ListNode*,vector<ListNode*>,compare>pq;
27
        pq.push(l1);
28
        pq.push(l2);
29
        if(pq.empty()) return NULL;
30
        ListNode* dummy=new ListNode(0);
31
        ListNode* head=dummy;
32
        while(!pq.empty())
33
        {
34
            ListNode* front=pq.top();
35
            pq.pop();
36
            
37
            head->next=front;
38
            head=head->next;
39
            
40
            if(front->next)
41
            pq.push(front->next);
42
        }
43
        return dummy->next;
44
        
45
    }
46
};
