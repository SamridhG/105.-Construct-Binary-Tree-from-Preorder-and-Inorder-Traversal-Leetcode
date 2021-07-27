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
    TreeNode *construct (vector<int>& preorder, vector<int>& inorder,int start,int end,int& index)
    {
        TreeNode *root=NULL;
        if(start<=end)
        {
            for(int i=start;i<=end;i++)
            {
                if(preorder[index]==inorder[i])
                {
                    root=new TreeNode(inorder[i]);
                    root->left=construct(preorder,inorder,start,i-1,++index);
                    root->right=construct(preorder,inorder,i+1,end,++index);
                    return root;
                }
            }
        }
        index--;
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index=0;
        return construct(preorder,inorder,0,inorder.size()-1,index);
    }
};
