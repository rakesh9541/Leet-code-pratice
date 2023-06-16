
    class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int size=nums.size();
        long sum=0;
        vector<vector<int>> ans;
        if(size<4)
            return ans;
        vector<int> vec(4);
        set<vector<int>> st;
        sort(nums.begin(),nums.end());
        for(int i=0;i<size-3;i++){
            int x=nums[i];
            for(int j=i+1;j<size-2;j++){
                int y=nums[j],ll=j+1,ul=size-1;
                sum=x+y;
                sum=target-sum;
                while(ll<ul){
                    long sum1=nums[ll]+nums[ul];
                    if(sum1==sum){
                        vec[0]=x,vec[1]=y,vec[2]=nums[ll],vec[3]=nums[ul];
                        st.insert(vec);
                        ll++;ul--;
                    }
                    else if(sum1<sum)
                        ll++;
                    else
                        ul--;
                }
            }
        }
        for(auto it: st)
            ans.push_back(it);
        return ans;
    }
};