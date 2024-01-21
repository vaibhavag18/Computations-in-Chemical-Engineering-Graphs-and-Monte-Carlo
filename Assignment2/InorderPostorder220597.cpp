class Solution
{
public:
    void createmapping(vector<int> inorder, map<int, int> &nodetoindex, int n)
    {
        for (int i = 0; i < n; i++)
        {
            nodetoindex[inorder[i]] = i;
        }
    }
    TreeNode *solve(vector<int> in, vector<int> post, int &index, int inorderstart, int inorderend, map<int, int> &nodetoindex, int n)
    {
        if (index < 0 || inorderstart > inorderend)
            return NULL;

        int element = post[index];
        TreeNode *root = new TreeNode(element);
        int position = nodetoindex[element];
        index -= 1;

        root->right = solve(in, post, index, position + 1, inorderend, nodetoindex, n);
        root->left = solve(in, post, index, inorderstart, position - 1, nodetoindex, n);

        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = inorder.size();
        int postorderindex = n - 1;

        map<int, int> nodetoindex;
        createmapping(inorder, nodetoindex, n);
        TreeNode *ans = solve(inorder, postorder, postorderindex, 0, n - 1, nodetoindex, n);
        return ans;
    }
};
