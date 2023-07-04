class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int cur=0;
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[cur]==nums[i]){
                count++;
            }
            if(count==3){
                i=0;
                count=1;
                cur++;
            }
        }
        int ans=nums[cur];
        return ans;
        
    }
};