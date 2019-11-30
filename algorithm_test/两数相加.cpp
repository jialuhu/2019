/*************************************************************************
	> File Name: 两数相加.cpp
	> Author: 
	> Mail: 
	> Created Time: 六 11/30 12:14:24 2019
 ************************************************************************/
/**
 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 
 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 
 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 
 示例：
 
 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 输出：7 -> 0 -> 8
 原因：342 + 465 = 807
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/add-two-numbers
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 **/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(-1);
        ListNode* head = result;
        int C_IN = 0;
        while(l1||l2){
            /*int sum = 0;
             if(l1){
             sum += l1->val;
             l1 = l1->next;
             }
             if(l2){
             sum += l2->val;
             l2 = l2->next;
             }
             sum += C_IN;
             C_IN = sum / 10;
             head->next = new ListNode(sum%10);
             head = head->next;
             }
             if(C_IN==1){
             head->next = new ListNode(C_IN);
             head = head->next;
             }*/
            if(l1 && l2){
                ListNode *stu = new ListNode((l1->val + l2->val+ C_IN)%10);
                C_IN = (l1->val+l2->val+C_IN)/10;
                head->next = stu;
                head = stu;
                l1=l1->next;
                l2 = l2->next;
            }else if(l1==NULL){
                ListNode *stu = new ListNode((l2->val+C_IN)%10);
                C_IN = (l2->val+0+C_IN)/10;
                head->next = stu;
                head = stu;
                l2 = l2->next;
            }else{
                ListNode *stu = new ListNode((l1->val+C_IN)%10);
                C_IN = (l1->val+0+C_IN)/10;
                head->next = stu;
                head = stu;
                l1 = l1->next;
            }
        }
        if(C_IN==1){
            head->next = new ListNode(C_IN);
            head = head->next;
        }
        return result->next;
    }
};

