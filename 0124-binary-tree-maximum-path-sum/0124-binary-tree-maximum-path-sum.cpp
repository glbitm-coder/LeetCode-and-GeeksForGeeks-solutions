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
    int maxPathSum(TreeNode* root) {
        if(root == NULL)
        {
            return INT_MIN;
        }
        int leftAns = maxPathSum(root->left);
        int rightAns = maxPathSum(root->right);
        long int ans1, ans2, ans3, ans4, ans5, ans6, leftVal, rightVal;
        if(!root->left)
        {
            leftVal = INT_MIN;
        }
        else
        {
            leftVal = root->left->val;
        }
        if(!root->right)
        {
            rightVal = INT_MIN;
        }
        else
        {
            rightVal = root->right->val;
        }
        ans1 = (long int)leftVal + root->val + (long int)rightVal;
        ans2 = (long int)rightVal + root->val;
        ans3 = (long int)leftVal + root->val;
        ans4 = (long int)leftAns;
        ans5 = (long int)rightAns;
        ans6 = (long int)root->val;
        long ans;
        ans = max(ans6, max(ans2, ans3));
        //cout<<root->val<<" "<<ans1<<" "<<ans2<<" "<<ans3<<" "<<ans4<<" "<<ans5<<" "<<ans6<<" "<<"\n";
        root->val = (int)ans;
        ans = max(max(ans,ans1), max(ans4, ans5));
        return ans;
    }
};