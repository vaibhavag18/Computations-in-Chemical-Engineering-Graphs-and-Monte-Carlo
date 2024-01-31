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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode *>q;
        q.push(root);
        int sum_max = INT_MIN;
        int init=1;
        int res= 1;

        while(!q.empty()){
            int size = q.size();
            int init_sum = 0;
            while(size--){
                TreeNode*init_node = q.front();
                q.pop();
                init_sum = init_sum + init_node->val;

                if(init_node->right){
                    q.push(init_node->right);
                }
                if(init_node->left){
                    q.push(init_node->left);
                }
            }
            if (sum_max < init_sum){
                sum_max = init_sum;
                res = init;
            }
            init++;
        }
        return res;

        
    }
};