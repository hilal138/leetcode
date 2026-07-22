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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        while(q.size()>0){
            int n = q.size();
            vector<int>v;
            if(level%2==0){
                for(int i=0;i<n;i++){
                    TreeNode* temp=q.front();
                    q.pop();
                    v.push_back(temp->val);
                    if(temp->left) q.push(temp->left);
                    if(temp->right) q.push(temp->right);
                }
                level++;
                ans.push_back(v);
            }
            else{
                for(int i=0;i<n;i++){
                    TreeNode* temp=q.front();
                    q.pop();
                    v.push_back(temp->val);
                    if(temp->left) q.push(temp->left);
                    if(temp->right) q.push(temp->right);
                }
                level++;
                reverse(v.begin(),v.end());
                ans.push_back(v);
            }
        }
        return ans;
    }
};