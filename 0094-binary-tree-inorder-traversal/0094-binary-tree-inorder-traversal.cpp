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
    vector<int> inorderTraversal(TreeNode* root) {
       TreeNode* curr = root;
        vector<int> ans;
        if(root == NULL)
        {
            return ans;
        }
        stack<TreeNode* > sck;
        sck.push(root);
        while(!sck.empty())
        {
            while(curr && curr->left != NULL)
            {
                curr = curr->left;
                sck.push(curr);
            }
            
            curr = sck.top();
            ans.push_back(curr->val);
            sck.pop();
            if(curr->right)
            {
                sck.push(curr->right);
            }
            curr = curr->right;
            
        }
        return ans;
    }
};