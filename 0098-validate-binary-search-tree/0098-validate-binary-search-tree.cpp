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
   bool isCheck(TreeNode* root, long int min,long int max)
   {
       if(root == NULL)
       {
           return true;
       }
       
       if(root->val <= min || root->val >= max)
       {
          
           return false;
       }
       
       return isCheck(root->left, min , root->val) && isCheck(root->right, root->val, max);
   }
    bool isValidBST(TreeNode* root) {
        return isCheck(root, LONG_MIN, LONG_MAX);
    }
};