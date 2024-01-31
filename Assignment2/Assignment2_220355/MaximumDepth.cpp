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
    int calculateMaxDepth(TreeNode* currentNode) {
        if (currentNode == nullptr) return 0;
        
        int leftSubtreeDepth = calculateMaxDepth(currentNode->left);
        int rightSubtreeDepth = calculateMaxDepth(currentNode->right);
        
        return 1 + std::max(leftSubtreeDepth, rightSubtreeDepth);
    }
};