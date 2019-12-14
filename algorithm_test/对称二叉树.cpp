/*************************************************************************
	> File Name: 对称二叉树.cpp
	> Author: 
	> Mail: 
	> Created Time: 六 12/14 20:38:59 2019
 ************************************************************************/

/**
 给定一个二叉树，检查它是否是镜像对称的。
 
 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
 
 1
 / \
 2   2
 / \ / \
 3  4 4  3
 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
 
 1
 / \
 2   2
 \   \
 3    3
 说明:
 
 如果你可以运用递归和迭代两种方法解决这个问题，会很加分。
 
 
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/symmetric-tree
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 **/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*递归法*/
 classSolution {
 public:
 bool ismirro(TreeNode* T1, TreeNode* T2){
     if(T1==NULL && T2==NULL) return true;
     if(T1==NULL || T2==NULL) return false;
     else{
         return(T1->val == T2->val) && ismirro(T1->left,T2->right) && ismirro(T1->right,T2->left);
     }
 }
bool isSymmetric(TreeNode* root) {
    return ismirro(root,root);
    }
};

/*队列，迭代法*/
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> Queue;
        Queue.push(root);
        Queue.push(root);
        while(!Queue.empty()){
            auto t1 = Queue.front();
            Queue.pop();
            auto t2 = Queue.front();
            Queue.pop();
            if(!t1 && !t2) continue;
            if(t1==NULL || t2 == NULL){
                return false;
            }
            if(t1->val!=t2->val){
                return false;
            }
            else{
                Queue.push(t1->left);
                Queue.push(t2->right);
                Queue.push(t1->right);
                Queue.push(t2->left);
            }
        }
        return true;
    }
};



