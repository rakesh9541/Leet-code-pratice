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
    unordered_map<string, int> present;
    vector<TreeNode*> res;
    string dfs(TreeNode* root) {
        string left = "", right = "", curr = "";
        if(!root) return "";
        left = dfs(root->left);
        right = dfs(root->right);
        curr = "(" + left + ")" + to_string(root->val) + "(" + right + ")";
        if(present[curr] == 1) res.push_back(root);
        present[curr]++;
        return curr;
   }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if(!root) return {};
        dfs(root);
        return res;
    }
};