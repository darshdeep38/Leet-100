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
    
        int maxSum; 

        int dfs(TreeNode* root){
            if(!root) return 0 ; 

        // Compute max path sum from left and right, discard negatives
        int left = max( 0  , dfs(root->left));
        int right = max(0 , dfs(root->right));

        // Case where this node is highest node 
        maxSum = max(maxSum , left + right + root->val);

        //return max one sided gain
        return root->val + max(left , right);
        }

        int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        dfs(root);
        return maxSum;

    }


    
};
