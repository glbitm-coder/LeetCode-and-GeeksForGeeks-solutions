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
    class ASL{
        public :
        int result = 0;
        int smallest = 0;
        int largest = 0;
        
        ASL(int result, int smallest, int largest)
        {
            this->result = result;
            this->smallest = smallest;
            this->largest = largest;
        }
    };
    ASL ans(TreeNode* root)
    {
        
       if(root == NULL){
           return ASL(0, INT_MAX, INT_MIN);
       }
         if(root->left == NULL && root->right == NULL)
        {
            return ASL(0, root->val, root->val);
        }
       
        ASL left_ans = ans(root->left);
        ASL right_ans = ans(root->right);
        
        int smallest_got = min(left_ans.smallest, right_ans.smallest);
        int largest_got = max(left_ans.largest, right_ans.largest);
        
        ASL required_ans_class(0,0,0);
        
        required_ans_class.result = max(max(left_ans.result, right_ans.result), max(abs(smallest_got - root->val), abs(largest_got - root->val )));
        
        required_ans_class.smallest = min(smallest_got, root->val);
        
        required_ans_class.largest = max(largest_got, root->val);
        
        return required_ans_class;
    }
    int maxAncestorDiff(TreeNode* root) {
         ASL root_val = ans(root);
        return root_val.result;
    }
};