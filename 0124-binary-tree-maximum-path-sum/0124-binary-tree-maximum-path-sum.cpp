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
    int maxSum(TreeNode* root, int &ans){
        if(root == NULL) return INT_MIN;
        ans = max(ans, root->val);
        if(root->left == NULL && root->right == NULL){
            return root->val;
        }
        int leftVal = 0,rightVal = 0;
        if(root->left){
            leftVal = maxSum(root->left,ans);
            ans = max(ans, max(leftVal, leftVal + root->val));
        }
        if(root->right){
            rightVal = maxSum(root->right, ans);
            ans = max(ans, max(rightVal, rightVal + root->val));
        }
        if(root->left && root->right){
            ans = max(ans, leftVal + rightVal + root->val);
        }
        cout<<root->val<<" "<<leftVal<<" "<<rightVal<<"\n";
        return max(max(root->val, root->val + leftVal), rightVal + root->val) ;
    }
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return 0;
        int ans = root->val;
        maxSum(root, ans);
        return ans;
    }
};