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
private:
    void in(TreeNode * root,int k,int &c,int &ans)
    {
        
        if(root==NULL)
        {
            return;
        }
        in(root->left,k,c,ans);
        
        if(++c==k)
        {
            ans = root->val;
            return ;
        }
        in(root->right,k,c,ans);
        
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int c=0;
        int ans = -1;
        in(root,k,c,ans);
        return ans;

        
    }
};