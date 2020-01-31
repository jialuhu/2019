/*************************************************************************
	> File Name: 倒叙链表.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  1/31 21:01:27 2020
 ************************************************************************/
/**
 输入一个链表，按链表从尾到头的顺序返回一个ArrayList 不改变链表结构
 **/
/**
 *  struct ListNode {
 *        int val;
 *        struct ListNode *next;
 *        ListNode(int x) :
 *              val(x), next(NULL) {
 *        }
 *  };
 */
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> arrayList;
        std::stack<ListNode*> nodes;
        ListNode* pNode = head;
        while(pNode != nullptr){
            nodes.push(pNode);
            pNode = pNode->next;
        }
        while(!nodes.empty()){
            pNode = nodes.top();
            arrayList.push_back(pNode->val);
            nodes.pop();
        }
        return arrayList;
    }
};
