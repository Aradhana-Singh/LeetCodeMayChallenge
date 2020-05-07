/*Cousins in Binary Tree */
/* In a binary tree, the root node is at depth 0, 
and children of each depth k node are at depth k+1.
Two nodes of a binary tree are cousins if they have the same depth, but have different parents.
We are given the root of a binary tree with unique values, 
and the values x and y of two different nodes in the tree.
Return true if and only if the nodes corresponding to the values x and y are cousins.
*/

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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode*,int>> q;
        TreeNode* temp; 
        q.push({root,0});
        int depthx=-1,depthy=-2;
        while(!q.empty()){
            pair <TreeNode*,int> p = q.front();
            q.pop();
            if(p.first->val == x) depthx = p.second;
            if(p.first->val == y) depthy = p.second;
            if(depthx == depthy) return true;
            
            
            //check if siblings
            if(p.first->left!=NULL &&p.first->right!=NULL){
                    if( (p.first->left->val == x && p.first->right->val == y) || 
                       (p.first->left->val == y && p.first->right->val == x)) return false;
            }
            if(p.first->left != NULL) {
                q.push({p.first->left,p.second+1});
            }
            if(p.first->right != NULL) {
                q.push({p.first->right,p.second+1});
            }
        }
        if(depthx == depthy) return true;
        else return false;
    }
};