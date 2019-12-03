/*************************************************************************
	> File Name: 反转链表.cpp
	> Author: 
	> Mail: 
	> Created Time: 二 12/ 3 21:14:37 2019
 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 反转一个单链表。
 
 示例:
 
 输入: 1->2->3->4->5->NULL
 输出: 5->4->3->2->1->NULL

 **/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        struct ListNode* Pre = NULL;
        struct ListNode* Curr = head;
        struct ListNode* Next = NULL;
        while(Curr){
            Next = Curr->next;
            Curr->next = Pre;
            Pre = Curr;
            Curr = Next;
        }
        return Pre;
    }
};

