class Solution {
public:
    int level(TreeNode* root){
    if(root==NULL) return 0;
    int leftlevels=level(root->left);
    int rightlevels=level(root->right);
    int ans = 1+ max((leftlevels),(rightlevels));
    return ans;
    }

    void nthLevel(TreeNode* root , int level, int curr, vector<int> &v ){
    if(root==NULL) return;
    if(curr==level){
        v.push_back(root->val);
        return;
    }
    nthLevel(root->left, level,curr+1,v);
    nthLevel(root->right , level , curr+1,v);
}

    void lOrder(TreeNode* root, vector<vector<int>>&ans){
    int n= level(root);
    for(int i=1;i<=n;i++){
        vector<int>v;
        nthLevel(root,i,1,v);
        ans.push_back(v);
        cout<<endl;
    }
}
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        lOrder(root , ans);
        return ans;

    }
};