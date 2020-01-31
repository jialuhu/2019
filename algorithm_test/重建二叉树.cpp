/*************************************************************************
	> File Name: 重建二叉树.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  1/31 21:01:45 2020
 ************************************************************************/
/**
 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
 **/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.size()==0||vin.size()==0){
            return nullptr;
        }
        vector<int> left_vin;
        vector<int> right_vin;
        vector<int> left_pre;
        vector<int> right_pre;
        TreeNode* Root = new TreeNode(0);
        Root->val = pre[0];
        Root->right = nullptr;
        Root->left = nullptr;
        if(pre.size()==1 && vin.size()==1 && pre[0]==vin[0]){
            return Root;
        }
        /*vin中序遍历*/
        int target = Root->val;
        bool flags = false;
        for(int i=0; i<vin.size(); i++){
            if(vin[i]!=target){
                if(!flags){
                    left_vin.push_back(vin[i]);
                }else{
                    right_vin.push_back(vin[i]);
                }
            }else{
                flags = true;
            }
        }
        
        int k = 1;
        for(int i=0; i<left_vin.size(); i++){
            left_pre.push_back(pre[k++]);
        }
        for(int i=0; i<right_vin.size(); i++){
            right_pre.push_back(pre[k++]);
        }
        
        Root->left = reConstructBinaryTree(left_pre,left_vin);
        Root->right = reConstructBinaryTree(right_pre,right_vin);
        return Root;
    }
};
