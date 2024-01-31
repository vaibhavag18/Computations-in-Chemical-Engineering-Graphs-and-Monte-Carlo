class Solution
{
public:
    int ans = 0;
    int prelevel = -1;
    void dfs(TreeNode *root, int l)
    {
        if (root == NULL)
            return;
        if (root->left == NULL and root->right == NULL)
        {
            if (l > prelevel)
            {
                ans = root->val;
                prelevel = l;
            }
            return;
        }
        prelevel = max(prelevel, l);
        if (root->left != NULL)
        {
            dfs(root->left, l + 1);
        }
        if (root->right != NULL)
        {
            dfs(root->right, l + 1);
        }
    }
    int findBottomLeftValue(TreeNode *root)
    {
        dfs(root, 0);
        return ans;
    }
};