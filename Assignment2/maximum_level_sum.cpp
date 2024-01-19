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
        vector<pair<int,int>> v;
        int ind=1;
        int sum= 0;
        if(root==NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node==NULL){
                int s=v.size();
                v.push_back({sum, s+1});
                sum=0;
                if(!q.empty()) q.push(NULL);
            }
            else{
                sum=sum+node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        sum=v[0].first;
        for(auto e:v){
            if(e.first>sum) {
                sum =e.first;
                ind=e.second;
            }
        }
        return ind;
    }
};