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
    void leafSequence(TreeNode* root, vector<int>& v)
    {
        if(root->left == NULL && root->right == NULL)
        {
             v.push_back(root->val);
        }
        if(root->left)
        {
            leafSequence(root->left, v);
        }
        if(root->right)
        {
            leafSequence(root->right, v);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;
        leafSequence(root1, v1);
        leafSequence(root2, v2);
        if(v1 == v2)
        {
            return true;
        }
        return false;
    }
};