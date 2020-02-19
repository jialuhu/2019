/*************************************************************************
	> File Name: 两个链表的第一个公共节点.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  2/19 21:39:12 2020
 ************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
 https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
 */
class Solution {
public:
    int getLength(ListNode* Head){
        int length = 0;
        ListNode* head = Head;
        while(head!=nullptr){
            head = head->next;
            length++;
        }
        return length;
        
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = getLength(headA);
        int lengthB = getLength(headB);
        int n = lengthA>=lengthB?(lengthA-lengthB):(lengthB-lengthA);
        ListNode *pheadlong;
        ListNode *pheadshort;
        if(lengthA>=lengthB){
            pheadlong = headA;
            pheadshort = headB;
        }else{
            pheadlong = headB;
            pheadshort = headA;
            
        }
        for(int i=0; i<n; i++){
            pheadlong = pheadlong->next;
        }
        while(pheadlong&&pheadshort&&pheadshort!=pheadlong){
            pheadlong = pheadlong->next;
            pheadshort = pheadshort->next;
        }
        
        ListNode *result = pheadshort;
        return result;
    }
};
