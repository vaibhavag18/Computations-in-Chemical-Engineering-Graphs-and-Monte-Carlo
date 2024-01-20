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
    #define ll long long
    int maxLevelSum(TreeNode* root) {
        map<int,ll> mp;
        queue<TreeNode*> q;
        q.push(root);
        int level=1;

        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto node=q.front();
                q.pop();

                mp[level]+=node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            level++;
        }

        ll sum=LLONG_MIN,minlevel=0;
        for(auto &it:mp){
            if(sum<it.second){
                minlevel=it.first;
                sum=it.second;
            }
        }
        return minlevel;
    }
};