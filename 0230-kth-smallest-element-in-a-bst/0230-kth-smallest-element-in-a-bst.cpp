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
    void iterate(TreeNode* root, priority_queue<int> &pq, int k){
        if(root == NULL) return;
        pq.push(root->val);
        if(pq.size() > k){
            pq.pop();
        }
        iterate(root->left, pq, k);
        iterate(root->right, pq, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int> pq;
        iterate(root, pq, k);
        return pq.top();
    }
};