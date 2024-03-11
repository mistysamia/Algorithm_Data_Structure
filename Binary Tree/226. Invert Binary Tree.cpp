#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int i = 0;
TreeNode *createTree(vector<int> &vec)
{
    if (i >= vec.size())
        return nullptr;

    TreeNode *tree = new TreeNode(vec[i++]);

    tree->left = createTree(vec);
    tree->right = createTree(vec);

    return tree;
}

TreeNode *invertTree(TreeNode *root)
{
    if (root == NULL)
        return nullptr;

    TreeNode *tree = new TreeNode(root->val);
    cout << tree->val << endl;
    tree->right = invertTree(root->left);
    tree->left = invertTree(root->right);

    return tree;
}

int main()
{

    int t = 100;

    while (t--)
    {
        int n, target, k, m;
        vector<int> nums, tums, ans;
        vector<string> str;
        vector<vector<int>> matrix, mat;
        string s, s1;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> k;
            nums.push_back(k);
        }

        TreeNode *root = createTree(nums);
        TreeNode *reverse = invertTree(root);
    }
}