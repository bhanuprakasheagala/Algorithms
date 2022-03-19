/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:

Input: head = [1], n = 1
Output: []

Example 3:

Input: head = [1,2], n = 1
Output: [1]

@LeetCode

*/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head, *slow = head , *prev = NULL;
        if (head->next == NULL) // when there is only one node in the linked list
            return NULL;
        for (int i = 0; i < (n-1); i++) //distance from the end node
        {
            fast = fast->next; 
        }
        while (fast->next!= NULL)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        if (prev == NULL) // that is the node to be deleted is the first node
            head = slow->next;
        else
        prev->next = slow->next;
        return head;
        
        
    }
};