class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>left,right;
        left.push_back(1);
        right.push_back(1);
        for(int i=0;i<n-1;i++)
        {
            int x=nums[i]*left[i];
            left.push_back(x);
        }
        for(int i=n-1;i>0;i--)
        {
            int y=nums[i]*right.back();
            right.push_back(y);
        }
        reverse(right.begin(),right.end());
        vector<int>ans;
        int n1=left.size();
        for(int i=0;i<n;i++)
        {
            ans.push_back(left[i]*right[i]);
        }
        return ans;
    }
};