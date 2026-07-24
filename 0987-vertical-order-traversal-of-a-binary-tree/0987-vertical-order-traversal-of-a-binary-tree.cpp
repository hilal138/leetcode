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
    typedef tuple<int,int,int> tp;
    typedef tuple<TreeNode*,int,int> t;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> ans;
    queue<t> q;
    priority_queue<tp, vector<tp>, greater<tp>> pq;

    q.push({root,0,0});

    while(!q.empty()){

        auto [node,col,row] = q.front();
        q.pop();

        pq.push({col,row,node->val});

        if(node->left)
            q.push({node->left,col-1,row+1});

        if(node->right)
            q.push({node->right,col+1,row+1});
    }

    while(!pq.empty()){

        auto [col,row,val] = pq.top();
        pq.pop();

        vector<int> temp;
        temp.push_back(val);

        while(!pq.empty() &&
              get<0>(pq.top())==col){

            temp.push_back(get<2>(pq.top()));
            pq.pop();
        }

        ans.push_back(temp);
    }

    return ans;
    }
};