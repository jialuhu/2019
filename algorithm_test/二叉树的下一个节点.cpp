/*************************************************************************
	> File Name: 二叉树的下一个节点.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  2/ 2 15:10:27 2020
 ************************************************************************/

/**
 给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
 **/

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if (pNode == nullptr)
            return pNode;
        if (pNode->right != nullptr) { // 节点有右子树
            pNode = pNode->right;
            while (pNode->left != nullptr) {
                pNode = pNode->left;
            }
            return pNode;
        } else if ( pNode->next != nullptr && pNode->next->left == pNode) { // 节点无右子树且该节点为父节点的左子节点
            return pNode->next;
        } else if (pNode->next != nullptr && pNode->next->right == pNode) { // 节点无右子树且该节点为父节点的右子节点
            while(pNode->next != nullptr && pNode->next->left != pNode){
                pNode = pNode->next ;
            }
            return pNode->next ;
        }else{
            return pNode->next ;//节点无父节点 ，即节点为根节点
        }
    }
};
