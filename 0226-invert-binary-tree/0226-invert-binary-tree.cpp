
class Solution {
public:
    void helper(TreeNode* root){
        if(root==NULL) return;
        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;
        helper(root->left);
        helper(root->right);

    }
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return root;
        helper(root);
        return root;
    }
};