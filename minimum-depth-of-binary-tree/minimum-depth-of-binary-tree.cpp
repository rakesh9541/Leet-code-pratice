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
    int minDepth(TreeNode* root) {
        if(!root) 
            return 0;
        int minLeft = minDepth(root->left);
        int minRight = minDepth(root->right);
        if(!root->left)
            return minRight+1;
        if(!root->right)
            return minLeft+1;
        return min(minLeft, minRight)+1;
        
    }
};