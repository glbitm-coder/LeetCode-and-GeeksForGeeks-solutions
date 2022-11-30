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
    TreeNode* insertIntoBST(TreeNode* root, int value) {
        if(root == NULL)
        {
             TreeNode* new_node = new TreeNode(value);
            return new_node;
        }
        if(value < root->val)
        {
            root->left = insertIntoBST(root->left, value);
        }
        else
        {
            root->right = insertIntoBST(root->right, value);
            
        }
        return root;
    }
};