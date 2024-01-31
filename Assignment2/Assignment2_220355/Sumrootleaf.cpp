/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int value;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : value(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : value(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : value(x), left(left), right(right) {}
 * };
 */
 
class Solution {
    int calculatePathSum(TreeNode* currentNode, int currentSum) {
        if (currentNode == nullptr) {
            return 0;
        }

        currentSum = currentSum * 10 + currentNode->value;

        if (currentNode->left == nullptr && currentNode->right == nullptr) {
            return currentSum;
        }

        int leftPathSum = calculatePathSum(currentNode->left, currentSum);
        int rightPathSum = calculatePathSum(currentNode->right, currentSum);

        return leftPathSum + rightPathSum;
    }

public:
    int sumNumbers(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        return calculatePathSum(root, 0);
    }
};
