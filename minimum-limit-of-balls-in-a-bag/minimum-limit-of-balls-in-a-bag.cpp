class Solution {
public:
bool check(int m,vector<int>& nums,int o){
    for(int i=0;i<nums.size(); i++)
    {
        o-=(nums[i]/m);
        if(nums[i]%m==0)o++;
    }
    return o>=0;
}
    int minimumSize(vector<int>& nums, int o) {
        int s=1, e=INT_MAX;
        int ans=0;
        while(s<=e){
            int m=s+(e-s)/2;
            if(check(m,nums,o))
            {
                ans=m;
                e=m-1;
            }
            else
            {
                s=m+1;
            }
        }
        return ans;
    }
};