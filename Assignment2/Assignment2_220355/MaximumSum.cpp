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
    int findMaxLevelSum(TreeNode* root) {
        std::queue<TreeNode*> nodeQueue;
        int maxSum = INT_MIN, currentSum = 0, levelCount = 0, resultLevel;
        nodeQueue.push(root);
        while (!nodeQueue.empty()) {
            int nodesInCurrentLevel = nodeQueue.size();
            levelCount++;
            currentSum = 0;
            while (nodesInCurrentLevel--) {
                TreeNode* currentNode = nodeQueue.front();
                nodeQueue.pop();
                currentSum += currentNode->value;
                if (currentNode->left)
                    nodeQueue.push(currentNode->left);
                if (currentNode->right)
                    nodeQueue.push(currentNode->right);
            }
            if (maxSum < currentSum) {
                maxSum = currentSum;
                resultLevel = levelCount;
            }
        }
        return resultLevel;
    }
};
