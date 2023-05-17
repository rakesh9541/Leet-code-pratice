class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) 
    {
        vector<int>ans(queries.size(), 0);
        vector<int>nums(n, 0);
        int count = 0;
        for (int i = 0; i < queries.size(); i++)
        {
            int index = queries[i][0],newCol = queries[i][1];
            int prevCol = (index - 1 < 0)? 0 : nums[index - 1];
            int nextCol = (index + 1 >= n)? 0 : nums[index + 1];
            int oldCol = nums[index];
            nums[index] = newCol;
            if (oldCol != 0 && oldCol == prevCol) count--;
            if (oldCol != 0 && oldCol == nextCol) count--;
            if (newCol == prevCol) count++;
            if (newCol == nextCol) count++;
            ans[i] = count;
        }
        return ans;
    }
};