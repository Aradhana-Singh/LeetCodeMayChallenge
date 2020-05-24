//Construct Binary Search Tree from Preorder Traversal
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
    void bstHelper(TreeNode* root, TreeNode* cur){
        if(root->left == nullptr && root->right == nullptr){
            if(root->val > cur->val)
                root->left = cur;
            else root->right = cur;
            return;
        }
        if(root->val > cur->val) {
            if(root->left==nullptr){
                root->left =cur;
                return;
            }
            bstHelper(root->left, cur);
            
        }
        else {
                if(root->right==nullptr){
                root->right =cur;
                return;
            }  
            bstHelper(root->right,cur);
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() == 0) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i = 1; i<preorder.size(); i++){
            TreeNode* cur = new TreeNode(preorder[i]);
            bstHelper(root,cur);
        }
        return root;
    }
};