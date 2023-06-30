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
   int Maxposition(vector<int>&nums,int left,int right){
       int indx=0;
       int maxi=INT_MIN;
       int n=nums.size();

       for(int i=left;i<=right;i++){
           if(nums[i]>maxi){
               maxi=nums[i];
               indx=i;
           }

       }
       return indx;
   }

    TreeNode*solve(TreeNode *root,vector<int>&nums,int left,int right){
        if(left>right){
            return NULL;
        }
        int pos=Maxposition(nums,left,right);
        root=new TreeNode(nums[pos]);
        root->left=solve(root->left,nums,left,pos-1);
        root->right=solve(root->right,nums,pos+1,right);

        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int left=0;
        int n=nums.size();
        int right=n-1;
        TreeNode *root=NULL;
        return solve(root,nums,left,right);
    }

};