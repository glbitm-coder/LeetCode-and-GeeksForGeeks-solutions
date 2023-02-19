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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int level = 0;
        vector<int> sub_ans;
        bool flag = false;
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        while(!q.empty())
        {
            auto curr = q.front();
            q.pop();
            
            if(curr == NULL)
            {
                if(flag)
                {
                    reverse(sub_ans.begin(), sub_ans.end());
                    ans.push_back(sub_ans);
                    flag = false;
                }
                else
                {
                    ans.push_back(sub_ans);
                    flag = true;
                }
                sub_ans.clear();
                if(!q.empty())
                {
                    q.push(NULL);
                }
            }
            else
            {
                sub_ans.push_back(curr->val);
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