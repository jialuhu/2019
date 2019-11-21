/*************************************************************************
	> File Name: 合并k个有序链表.cpp
	> Author: 
	> Mail: 
	> Created Time: 四 11/21 20:33:51 2019
 ************************************************************************/
/**
 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
 
 示例:
 
 输入:
 [
   1->4->5,
   1->3->4,
   2->6
 ]
 输出: 1->1->2->3->4->4->5->6
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/merge-k-sorted-lists
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*分治思想求解*/
class Solution {
public:
    ListNode* mergeFenzhi(vector<ListNode*>& lists, int left, int right){
        if(left==right){
            return lists[left];
        }
        int mid = (left+right)/2;
        ListNode* list_l = mergeFenzhi(lists,left,mid);//最初将此处的第三处mid设置为了mid-1，此处left < mid < right一定成立，但是left<mid-1无法确认成立。会出现溢出。所以只能mid,mid+1
        ListNode* list_r = mergeFenzhi(lists,mid+1,right);
        return mergeTwoLists(list_l, list_r);
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        if(l1==NULL&&l2==NULL){
            return NULL;
        }
        if(l1!=NULL&&l2==NULL){
            return l1;
        }
        if(l1==NULL&&l2!=NULL){
            return l2;
        }
        ListNode *result = new ListNode(-1);
        ListNode *head = result;
        while(l1 && l2){
            if(l1->val >= l2->val){
                head->next = l2;
                l2 = l2->next;
            }else{
                head->next = l1;
                l1 = l1->next;
            }
            head = head->next;
        }
        if(l1){
            head->next = l1;
        }else{
            head->next = l2;
        }
        return result->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int left = 0;
        int right = lists.size();
        if(right==0){
            return NULL;
        }
        return mergeFenzhi(lists,left,right-1);
    }
};

//分治非递归
class Solution {
public:
    ListNode* mergeTwoList(ListNode* l1, ListNode* l2){
        if(l1==NULL&&l2==NULL){
            return NULL;
        }
        if(l1!=NULL&&l2==NULL){
            return l1;
        }
        if(l1==NULL&&l2!=NULL){
            return l2;
        }
        ListNode *result = new ListNode(-1);
        ListNode *head = result;
        while(l1 && l2){
            if(l1->val >= l2->val){
                head->next = l2;
                l2 = l2->next;
            }else{
                head->next = l1;
                l1 = l1->next;
            }
            head = head->next;
        }
        if(l1){
            head->next = l1;
        }else{
            head->next = l2;
        }
        return result->next;
        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int left = 0;
        int right = lists.size()-1;
        if((right+1)==0){
            return NULL;
        }
        while(right>0){
            while(left < right){
                lists[left] = mergeTwoList(lists[left], lists[right]);
                left++;
                right--;
            }
            left=0;
        }
        return lists[0];
    }
};
