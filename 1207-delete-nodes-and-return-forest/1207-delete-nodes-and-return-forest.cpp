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
    void nodes(TreeNode* root, vector<TreeNode*> &ans, unordered_set<int> &s){
        if(root == NULL){
            return;
        }
        if(s.find(root->val) != s.end()){
            if(root->left){
                if(s.find(root->left->val) != s.end()){
                    nodes(root->left, ans, s);
                }
                else{
                    ans.push_back(root->left);
                    nodes(root->left, ans, s);
                }
            }
            if(root->right){
                if(s.find(root->right->val) != s.end()){
                    nodes(root->right, ans, s);
                }
                else{
                    ans.push_back(root->right);
                    nodes(root->right, ans, s);
                }
            }
            root = NULL;
        }
        else{
            if(root->left){
                if(s.find(root->left->val) != s.end()){
                    auto it = root->left;
                    root->left = NULL;
                    nodes(it, ans, s);
                }
                else{
                    nodes(root->left, ans, s);
                }
            }
            if(root->right){
                if(s.find(root->right->val) != s.end()){
                    auto it = root->right;
                    root->right = NULL;
                    nodes(it, ans, s);
                }
                else{
                    nodes(root->right, ans, s);
                }
            }
        }
        
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;

        
        unordered_set<int> s;
        for(int i = 0; i < to_delete.size(); ++i){
            s.insert(to_delete[i]);
        }

        if(s.find(root->val) == s.end()){
            ans.push_back(root);
        }
        nodes(root, ans, s);
        
        return ans;
    }
};