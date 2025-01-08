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
    TreeNode* create(int &curr, vector<int> &preorder, vector<int> &inorder, int inStart, int inEnd){

        if(inStart > inEnd) return NULL;
        TreeNode* node = new TreeNode(preorder[curr]);
        int idx = -1;
        for(int i = inStart; i <= inEnd; ++i){
            if(preorder[curr] == inorder[i]){
                idx = i;
                break;
            }
        }
        ++curr;
        node->left = create(curr, preorder, inorder, inStart, idx - 1);
        node->right = create(curr, preorder, inorder, idx + 1, inEnd);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* node = new TreeNode(preorder[0]);
        int curr = 0;
        return create(curr, preorder, inorder, 0, inorder.size() - 1);
    }
};