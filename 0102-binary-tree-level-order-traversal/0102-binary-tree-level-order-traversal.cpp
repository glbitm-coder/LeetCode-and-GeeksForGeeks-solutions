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
        queue<TreeNode*> que;
        vector<vector<int>> ans;
        if(root == NULL) return ans;

        vector<int> subAns;
        que.push(root);
        que.push(NULL);
        while(!que.empty()){
            TreeNode* temp = que.front();
            que.pop();
            if(temp != NULL){
                subAns.push_back(temp->val);
                if(temp->left){
                    que.push(temp->left);
                }
                if(temp->right){
                    que.push(temp->right);
                }
            }
            else{
                ans.push_back(subAns);
                subAns.clear();
                if(!que.empty()){
                    que.push(NULL);
                }
            }
        }
        return ans;
    }
};