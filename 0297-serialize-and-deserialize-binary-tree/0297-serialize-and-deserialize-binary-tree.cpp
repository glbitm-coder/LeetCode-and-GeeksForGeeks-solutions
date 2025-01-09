/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL){
            return "@";
        }
        string ans =  '[' + to_string(root->val) + ']' + serialize(root->left) + serialize(root->right);
        cout<<ans<<"\n";
        return ans;
  }

    // Decodes your encoded data to tree.
    TreeNode* decode(string &data, int &curr){
        cout<<curr<<"\n";
        if(data[curr] == '@'){
            ++curr;
            return NULL;
        }
        ++curr;
        string str = "";
        int num = 1;
        if(data[curr] == '-'){
            ++curr;
            num = -1;
        }
        while(data[curr] != ']'){
            str = str + data[curr];
            ++curr;
        }
        num = num * stoi(str);
        TreeNode* node = new TreeNode(num);
        ++curr;
        node->left =  decode(data, curr);
        node->right = decode(data, curr);
        return node;
    }
    TreeNode* deserialize(string data) {
        int curr = 0;
        return decode(data, curr);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));