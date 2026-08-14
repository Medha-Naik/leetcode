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
    int maxsum = INT_MIN;
    int dfs(TreeNode * root)
    {
        if(root== NULL) return 0;
        int leftgain = max(0, dfs(root->left));
        int rightgain = max(0, dfs(root->right));
        int cursum= root->val + leftgain+ rightgain;
        maxsum = max(maxsum, cursum);
        return root->val + max(leftgain, rightgain);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxsum;
    }
};