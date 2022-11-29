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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root == NULL)
        {
            return ans;
        }
        q.push(root);
        q.push(NULL);
        vector<int> sub_ans;
        TreeNode* curr;
        while(!q.empty())
        {
            curr = q.front();
            
            if(curr == NULL)
            {
                ans.push_back(sub_ans);
                sub_ans.clear();
                q.pop();
                if(!q.empty())
                {
                    q.push(NULL);
                }
            }
            else{
                sub_ans.push_back(curr->val);
                
                q.pop();
                if(curr->left)
                {
                    q.push(curr->left);
                }
                if(curr->right)
                {
                    q.push(curr->right);
                }
            }
        }
        return ans;
    }
};