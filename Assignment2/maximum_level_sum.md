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
        int curr_level = 1;
        int ans_level = 1;
        queue<TreeNode*> q;
        q.push(root);
        int max_sum = root->val;

        while(q.empty()==0){
            int curr_sum = 0;
            int n = q.size();
            for(int i = 0;i<n;i++){
                 auto curr = q.front();
                 q.pop();
                 if(curr->left != NULL){
                     q.push(curr->left);
                 }
                 if(curr->right !=NULL){
                     q.push(curr->right);
                 }
                 curr_sum+=curr->val;
            }
            if(curr_sum>max_sum){
                max_sum = curr_sum;
                ans_level = curr_level;
            }
            curr_level += 1;
        }
        return ans_level;
    }
};