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
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 1;
        
        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);
        int val;
        if(leftDepth == 0) val = rightDepth;
        else if(rightDepth == 0) val = leftDepth;
        
        if(leftDepth != 0 && rightDepth != 0) val = min(leftDepth, rightDepth);
        return val + 1;
    }
};