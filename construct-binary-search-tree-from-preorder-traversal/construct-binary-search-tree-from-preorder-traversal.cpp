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
    TreeNode* fun(int &i,vector<int>&preorder,int bound)
    {
        if(i==preorder.size() || preorder[i]>bound)
            return NULL;
        TreeNode* node=new TreeNode(preorder[i++]);
        node->left=fun(i,preorder,node->val);
        node->right=fun(i,preorder,bound);
    return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return fun(i,preorder,INT_MAX);
        
    }
    
};