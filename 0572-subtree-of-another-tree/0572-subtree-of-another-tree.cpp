/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool ifFound(TreeNode* root, TreeNode* subRoot){
        if(root == NULL && subRoot == NULL) return true;
        if(root && subRoot == NULL) return false;
        if(root == NULL && subRoot) return false;
        if(root->val == subRoot->val){
            return ifFound(root->left,subRoot->left) && ifFound(root->right,subRoot->right);
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL && subRoot == NULL) return true;
        if(root && subRoot == NULL) return false;
        if(root == NULL && subRoot) return false;
        if(root->val == subRoot->val){
            if(ifFound(root, subRoot)) return true; 
        }
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};