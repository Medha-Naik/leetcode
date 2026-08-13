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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode *> st;
        vector<int>inorder;
        while(true)
        {
            if(root!=NULL)
            {
                st.push(root);
                root= root->left;

            }
            else{
                if(st.empty())break;
                TreeNode * node = st.top();
                st.pop();
                inorder.push_back(node->val);
                root = node->right;
            }
        }
        return inorder;
    }
};