//Kth Smallest Element in a BST
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
    int n, ans;
    void traverse(TreeNode *root)
    {
        if(!root)   return;
        
        if(root->left)                         // traverse left
            traverse(root->left);
        
        if(--n==0)                                   // if count becomes zero , means we have reached nth node in INORDER traversal
            { 
			    ans = root->val;   // store answer
				return;                   // stop traversing, no need to go futher since we have already reached the answer
			}
        
        if(root->right)
            traverse(root->right);
            
    }
    int kthSmallest(TreeNode* root, int k) {
        n=k;
        traverse(root);
        return ans;
    }
};