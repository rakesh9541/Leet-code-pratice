class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int min_diff=INT_MAX;
        sort(nums.begin(), nums.end());
        int n=nums.size(), closest_sum=0;
        for(int i=0; i<n-2; ++i){
            int start=i+1, end=n-1;
            while(start<end){
                int sum= nums[i]+nums[start]+nums[end];
                if(sum<target)
                    start++;
                else if(sum>target)
                    end--;
                else return sum;
                int diff=abs(sum-target);
                if(diff<min_diff){
                    min_diff=diff;
                    closest_sum=sum;
                }
            }
        }
        return closest_sum;
    }
};