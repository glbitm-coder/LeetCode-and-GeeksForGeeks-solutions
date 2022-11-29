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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL)
        {
            return ans;
        }
        TreeNode* curr = root, *prev = root;
         stack<TreeNode*> sck;
        while(true)
        {
            //Find the leftmost child
            while(curr->left != NULL)
            {
                sck.push(curr);
                curr = curr->left;
            }
            //Popping the nodes  until untraversed right subtree is not there
            while(curr->right == NULL || curr->right == prev)
            {
                ans.push_back(curr->val);
                prev = curr;
                if(sck.empty())
                {
                    return ans;
                }
                curr = sck.top();
                sck.pop();
                
            }
            sck.push(curr);
            curr = curr->right;
        }
    }
};