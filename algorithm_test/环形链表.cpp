/*************************************************************************
	> File Name: 环形链表.cpp
	> Author: 
	> Mail: 
	> Created Time: 日 12/15 12:21:03 2019
 ************************************************************************/

/**
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/linked-list-cycle
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
    /*set集合解决*/
    bool hasCycle(ListNode *head) {
        set<ListNode*> maps;
        while(head){
            if(maps.count(head)!=0){
                return true;
            }else{
                maps.insert(head);
            }
            head = head->next;
        }
        return false;
    }
    /*双指针解决*/
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return false;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(slow != fast){
            if(fast==NULL || fast->next==NULL){
                return false;
            }else{
                slow = slow->next;
                fast = fast->next->next;
            }
        }
        return true;
    }
};
