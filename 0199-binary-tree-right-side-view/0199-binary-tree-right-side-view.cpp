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
    void levelOrder(TreeNode* root, vector<vector<int>> &ans) {
        queue<TreeNode*> que;
        if(root == NULL) return ;

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
        return ;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> ans;
        levelOrder(root, ans);
        vector<int> res;
        for(int i = 0; i < ans.size(); ++i){
            res.push_back(ans[i][ans[i].size() - 1]);
        }
        return res;
    }
};