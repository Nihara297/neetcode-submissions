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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[0]);
        int pos=0;
        while(inorder[pos]!=preorder[0]){
            pos++;
        }
        vector<int>leftin(inorder.begin(), inorder.begin()+pos);
        vector<int>rightin(inorder.begin()+pos+1, inorder.end());
        vector<int>leftpre(preorder.begin()+1,preorder.begin()+1+leftin.size());
        vector<int>rightpre(preorder.begin()+1+leftin.size(), preorder.end());
        root->left=buildTree(leftpre, leftin);
        root->right=buildTree(rightpre, rightin);
        return root;
    }
};
