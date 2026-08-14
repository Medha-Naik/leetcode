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
     int maxdiameter =0;
    int Height(TreeNode * root)
    {
        if(root == NULL) return 0;
        int lh = Height( root ->left);
        int rh = Height(root->right);
        maxdiameter = max( maxdiameter, lh+rh);
        return max(lh,rh)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        Height(root);
        return maxdiameter;
    }
};