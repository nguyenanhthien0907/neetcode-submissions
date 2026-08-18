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
        // #way 1 use queue
        // if (root == nullptr){
        //     return 0;
        // }
        // queue<TreeNode *>q;
        // q.push(root);
        // int level = 0;
        // while(!q.empty()){
        //     size_t levelsSize = q.size();
        //     for (size_t i = 0; i < levelsSize; i++){
        //         TreeNode *current = q.front();
        //         q.pop();
        //         if (current->left != nullptr){
        //             q.push(current->left);
        //         }
        //         if (current->right != nullptr){
        //             q.push(current->right);
        //         }
        //     }
        //     level++;
        // }
        // return level;
        // #way 2: use recursion
        // if (root == nullptr){
        //     return 0;
        // }
        // return 1 + max(maxDepth(root->left), maxDepth(root->right));
        //
//         private:
//     int maxDepthHelper(TreeNode* root, int currDepth) {
//         if (!root) return currDepth;

//         return std::max(maxDepthHelper(root->left, currDepth+1), maxDepthHelper(root->right, currDepth+1));
//     }
// public:
//     int maxDepth(TreeNode* root) {
//         return maxDepthHelper(root, 0);
//     }
        // #way 3: use stack
        stack<pair<TreeNode*, int>> stack;
        stack.push({root, 1});
        int res = 0;

        while (!stack.empty()) {
            pair<TreeNode*, int> current = stack.top();
            stack.pop();
            TreeNode* node = current.first;
            int depth = current.second;

            if (node != nullptr) {
                res = max(res, depth);
                stack.push({node->left, depth + 1});
                stack.push({node->right, depth + 1});
            }
        }
        return res;
    }
};
