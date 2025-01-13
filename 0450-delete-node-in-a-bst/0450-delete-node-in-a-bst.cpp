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
    TreeNode* Minimum(TreeNode *root)
    {
        if(root==NULL)
        {
            return NULL;
        }
        TreeNode* temp = root;
        while(temp->left !=NULL)
        {
            temp=temp->left;
        }
        return temp;
    }
public:
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root ==NULL )
        {
            return root;
        }
        if(root -> val ==key)
        {
            if(root->left ==NULL && root->right ==NULL)
            {
                delete root;
                return NULL;
            }
            else if(root->left ==NULL && root->right !=NULL)
            {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
            else if(root->left !=NULL && root->right ==NULL )
            {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            else
            {
                int m = Minimum(root->right)->val;
                root->val = m;
                root->right = deleteNode(root->right,m);
                return root;
            }
        }
        if(key>root->val)
        {
            root->right = deleteNode(root->right,key);
        }
        if(key<root->val)
        {
            root->left = deleteNode(root->left,key);
        }
        return root;
    }
};