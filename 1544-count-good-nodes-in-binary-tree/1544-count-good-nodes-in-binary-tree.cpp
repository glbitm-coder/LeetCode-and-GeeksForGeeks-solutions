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
    int isGood(TreeNode* root, int value){
        if(root == NULL) return 0;
        int le = isGood(root->left, max(value, root->val));
        int ri = isGood(root->right, max(value, root->val));
        if(root->val >= value){
            return le + ri + 1;
        }
        return le + ri;
    }
    int goodNodes(TreeNode* root) {
        return isGood(root, INT_MIN);
    }
};