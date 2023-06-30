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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if( p==NULL && q==NULL) return true;
        if( p!=NULL && q== NULL) return false;
        if( p==NULL && q!=NULL) return false;
        if( p->val==q->val){
            bool f1 = isSameTree( p->right, q->left);
            bool f2 = isSameTree( p->left, q->right);
            return (f1&&f2);

        }
            
        return false;

    }   
    
    bool isSymmetric(TreeNode* root) {
        if( root==NULL) return true;
        return isSameTree(root->left , root->right);
    }
};