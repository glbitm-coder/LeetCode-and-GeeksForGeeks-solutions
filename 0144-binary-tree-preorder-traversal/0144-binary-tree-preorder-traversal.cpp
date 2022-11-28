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
        
        stack<TreeNode* > sck;
        vector<int> ans;
        
        if(root == NULL)
        {
            return ans;
        }
        sck.push(root);
        while(!sck.empty())
        {
            TreeNode* curr = sck.top();
            ans.push_back(curr->val);
            sck.pop();
            if(curr->right)
            {
                sck.push(curr->right);
            }
            if(curr->left)
            {
                sck.push(curr->left);
            }
        }
        return ans;
        
    }
};