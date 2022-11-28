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
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        if(root == NULL)
        {
            return ans;
        }
        vector<int> leftValues = preorderTraversal(root->left);
        vector<int> rightValues = preorderTraversal(root->right);
        ans.insert(ans.begin(), root->val);
        ans.insert(ans.end(), leftValues.begin(), leftValues.end());
        ans.insert(ans.end(), rightValues.begin(), rightValues.end());
        return ans;
    }
};