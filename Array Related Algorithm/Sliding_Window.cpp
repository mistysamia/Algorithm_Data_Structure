// Efficiently handle substring or subarray search, maximize/minimize values within a window and optimize algorithms using a fixed-size window of elements.

#include <bits/stdc++.h>
using namespace std;

int maxSumSubarray(vector<int> &nums, int k)
{
    int maxSum = INT_MIN;
    int windowSum = 0;

    for (int i = 0; i < nums.size(); ++i)
    {
        windowSum += nums[i];
        if (i >= k - 1)
        {
            maxSum = max(maxSum, windowSum);
            windowSum -= nums[i - (k - 1)];
        }
    }

    return maxSum;
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
        cin >> k >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> m;
            nums.push_back(m);
        }

        cout << maxSumSubarray(nums, k) << endl;
    }
}

/*
K = 2
nums = -1 3 -1 -3 5 3 6 7
2
8
-1 3 -1 -3 5 3 6 7

*/