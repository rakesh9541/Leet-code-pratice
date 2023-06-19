class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        int r=n-k;
        reverse(nums.begin(),nums.begin()+r);
        reverse(nums.begin()+r,nums.end());
        reverse(nums.begin(),nums.end());
        
    }
};