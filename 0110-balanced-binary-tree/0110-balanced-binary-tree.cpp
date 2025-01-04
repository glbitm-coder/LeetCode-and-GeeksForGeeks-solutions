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
    int maxDepth(TreeNode* root, bool &ans) {
        if(root == NULL) return 0;
        int leftVal = maxDepth(root->left, ans);
        int rightVal = maxDepth(root->right, ans);
        if(leftVal - rightVal  < -1 || leftVal - rightVal > 1){
            ans = false;
        }
        return max(leftVal, rightVal) + 1;
    }
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        maxDepth(root, ans);
        return ans;
    }
};