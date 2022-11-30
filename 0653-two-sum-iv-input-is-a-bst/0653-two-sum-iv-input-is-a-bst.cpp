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
    bool findpair(TreeNode* root, int sum, unordered_set<int>& st)
    {
        if(root == NULL)
        {
            return false;
        }
        if(st.find(sum - root->val) != st.end())
        {
            return true;
        }
        else
        {
            st.insert(root->val);
        }
        bool ans1 = findpair(root->left, sum, st);
        bool ans2 = findpair(root->right, sum, st);
        return ans1 || ans2;
        
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> st;
    return findpair(root, k, st);
    }
};