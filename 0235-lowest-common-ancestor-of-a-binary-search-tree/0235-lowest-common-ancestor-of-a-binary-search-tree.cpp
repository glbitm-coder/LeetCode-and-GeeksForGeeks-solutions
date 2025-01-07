/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        TreeNode* l = NULL, *r = NULL;
        l = lowestCommonAncestor(root->left, p, q);
        r = lowestCommonAncestor(root->right, p, q);

        if(l || r){
            if(l && r){
                return root;
            }
            else if(l){
                if(root->val == p->val || root->val == q->val) return root;
                return l;
            }
            else{
                if(root->val == p->val || root->val == q->val) return root;
                return r;
            }
        }
        else{
            if(root->val == p->val || root->val == q->val){
                return root;
            }
            else{
                return NULL;
            }
        }

    }
};