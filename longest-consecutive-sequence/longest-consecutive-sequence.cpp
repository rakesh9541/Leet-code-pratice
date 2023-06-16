class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>s;
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }
        int longstreak=0;
        for(int i=0;i<nums.size();i++)
        {
            if(!s.count(nums[i]-1))
            {
                int curr=nums[i];
                int currstreak=1;
                while(s.count(curr+1))
                {
                    curr+=1;
                    currstreak+=1;
                }
                longstreak=max(longstreak,currstreak);
            }
        }
        return longstreak;
    }
};