
class Solution {
public:
    int LeftHeight(TreeNode* root){
        if(root==NULL ) return 0;
        return 1 + LeftHeight(root->left);
    }
    int RightHeight(TreeNode* root){
        if(root==NULL ) return 0;
        return 1 + RightHeight(root->right);
    }

    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int lft = LeftHeight(root);
        int rgt = RightHeight(root);
        if(lft==rgt) return (1<<lft)-1;
        else return 1 + countNodes(root->left) + countNodes(root->right);
    }
};