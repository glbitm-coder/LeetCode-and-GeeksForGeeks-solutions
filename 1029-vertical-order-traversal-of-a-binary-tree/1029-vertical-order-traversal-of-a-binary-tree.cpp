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
    void helper(TreeNode* root, int row, int col, map<int, vector<pair<int,int>>> &mp){
        if(root == NULL) return;
        mp[col].push_back({row, root->val});
        helper(root->left, row + 1, col - 1, mp);
        helper(root->right, row + 1, col + 1, mp);

    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, vector<pair<int,int>>> mp;
        helper(root, 0, 0, mp);
        for(auto it:mp){
            vector<pair<int,int>> an = it.second;
            sort(an.begin(), an.end());
            vector<int> a;
            for(auto i:an){
                a.push_back(i.second);
            }
            ans.push_back(a);
        }
        
        return ans;
    }
};