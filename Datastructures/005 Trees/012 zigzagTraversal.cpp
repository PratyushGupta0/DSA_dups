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
    void fun(TreeNode* root, vector<vector<int> >& res, int level){

        if(root==nullptr) return;
        if(level==res.size()) res.push_back({});

        res[level].push_back(root->val);
        fun(root->left, res, level+1);
        fun(root->right, res, level+1);

    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int> > res;
        fun(root, res, 0);

        for(int i=1; i<res.size(); i+=2)
            reverse(res[i].begin(), res[i].end());

        return res;
    }
};
