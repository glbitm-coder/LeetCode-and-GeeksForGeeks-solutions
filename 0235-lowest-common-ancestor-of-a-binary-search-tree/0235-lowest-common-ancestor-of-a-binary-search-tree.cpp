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
   void findforq(TreeNode* root, TreeNode* q,  unordered_set<TreeNode*>& forq)
    {
        if(q->val < root->val)
        {
            forq.insert(root);
            findforq(root->left, q, forq);
        }
       else if(q->val > root->val)
       {
           forq.insert(root);
           findforq(root->right, q, forq);
       }
       else{
           forq.insert(root);
       }
    }
    void findforp(TreeNode* root, TreeNode* p,  vector<TreeNode*>& checkp)
    {
        if(p->val < root->val)
        {
           checkp.push_back(root);
            findforp(root->left, p, checkp);
        }
       else if(p->val > root->val)
       {
           checkp.push_back(root);
           findforp(root->right, p, checkp);
       }
       else{
           checkp.push_back(root);
       }
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> checkp;
        findforp(root, p, checkp);
        unordered_set<TreeNode*> forq;
        findforq(root, q, forq);
        for(int i = (int)checkp.size() - 1; i >= 0; --i)
        {
            if(forq.find(checkp[i]) != forq.end())
            {
                return checkp[i];
            }
        }
        return NULL;
    }
};