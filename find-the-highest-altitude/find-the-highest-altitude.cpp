class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum=0,maxi=0;
        for(int i=0;i<gain.size();i++)
        {
            sum=sum+gain[i];
            if(sum>0)
                maxi=max(maxi,sum);
        }
        return maxi;
        
    }
};