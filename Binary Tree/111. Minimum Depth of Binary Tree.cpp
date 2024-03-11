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
  int minDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        deque<TreeNode *> deq;
        map<TreeNode *, int> mp;

        deq.push_back(root);
        mp[root] = 1;

        while (!deq.empty())
        {
            TreeNode *current = deq.front();
            deq.pop_front();

            if (current->left == NULL && current->right == NULL)
                return mp[current];

            if (current->left != NULL)
            {
                deq.push_back(current->left);
                mp[current->left] = mp[current] + 1;
            }

            if (current->right != NULL)
            {
                deq.push_back(current->right);
                mp[current->right] = mp[current] + 1;
            }
        }
        return 0;
    }
};