/*************************************************************************
	> File Name: 平衡二叉树.cpp
	> Author: 
	> Mail: 
	> Created Time: 四 12/12 21:33:49 2019
 ************************************************************************/

/**
 给定一个二叉树，判断它是否是高度平衡的二叉树。
 
 本题中，一棵高度平衡二叉树定义为：
 
 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
 
 示例 1:
 
 给定二叉树 [3,9,20,null,null,15,7]
 
 3
 / \
 9  20
 /  \
 15   7
 返回 true 。
 
 示例 2:
 
 给定二叉树 [1,2,2,3,3,null,null,4,4]
 
 1
 / \
 2   2
 / \
 3   3
 / \
 4   4
 返回 false 。
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/balanced-binary-tree
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
class Solution {
public:
    //-1截断法
    /*int height(TreeNode* root){
     if(root==NULL){
        return 0;
    }
    int left_h = height(root->left);
    int right_h = height(root->right);
    
    if(left_h>=0&&right_h>=0 && abs(left_h-rig  ht_h)<=1){
     
        return max(left_h,right_h)+1;
     
     }else{
        return -1;
    }
}
     
     bool isBalanced(TreeNode* root) {
     if(root==NULL){
        return true;
     }
        return height(root)>=0;
     }*/

    
//该方法之前有错，是由于只计算了根节点下的左右子树，并没有一直遍历计算了每个结点的左右子树，
//现在已经修正
int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left_h = height(root->left);
        int right_h = height(root->right);
        return (left_h>right_h?left_h:right_h)+1;
}
bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        int left = height(root->left);
        int right = height(root->right);
        return (left > right ? (left - right <= 1) : (right - left <= 1))&& isBalanced(root->left)&&isBalanced(root->right);
    }
};
