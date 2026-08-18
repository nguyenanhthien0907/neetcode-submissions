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
    int maxDepth(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }
        queue<TreeNode *>q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            size_t levelsSize = q.size();
            for (size_t i = 0; i < levelsSize; i++){
                TreeNode *current = q.front();
                q.pop();
                if (current->left != nullptr){
                    q.push(current->left);
                }
                if (current->right != nullptr){
                    q.push(current->right);
                }
            }
            level++;
        }
        return level;
    }
};
