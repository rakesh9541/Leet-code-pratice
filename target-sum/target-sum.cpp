class Solution {
public:
    map<pair<int,int>,int> m;
    int rec(vector<int> & nums,int t,int i)
    {
        if(i>=nums.size())
        {
            if(t==0)
            return 1;
            else
                return 0;
        }
        if(m.find({i,t})!=m.end())
        {
            return m[{i,t}];
        }
        return m[{i,t}]=rec(nums,t-nums[i],i+1)+rec(nums,t+nums[i],i+1);
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return rec(nums,target,0);
    }
};