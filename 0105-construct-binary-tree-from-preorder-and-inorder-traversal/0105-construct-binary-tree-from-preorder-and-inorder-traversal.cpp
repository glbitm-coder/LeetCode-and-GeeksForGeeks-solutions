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
    TreeNode* create(int &curr, vector<int> &preorder, vector<int> &inorder, int inStart, int inEnd, unordered_map<int,int> &mp){

        if(inStart > inEnd) return NULL;
        TreeNode* node = new TreeNode(preorder[curr]);
        int idx = -1;
        
        idx = mp[preorder[curr]];
        ++curr;
        node->left = create(curr, preorder, inorder, inStart, idx - 1, mp);
        node->right = create(curr, preorder, inorder, idx + 1, inEnd, mp);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* node = new TreeNode(preorder[0]);
        int curr = 0;
        unordered_map<int,int> mp;
        for(int i = 0; i < inorder.size(); ++i){
            mp[inorder[i]] = i;
        }
        return create(curr, preorder, inorder, 0, inorder.size() - 1, mp);
    }
};