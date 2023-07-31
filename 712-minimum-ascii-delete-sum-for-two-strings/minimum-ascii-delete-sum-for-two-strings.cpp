class Solution {
public:

	int f(int i,int j,string& s1,string& s2,vector<vector<int>>& dp){
		if(i<0 || j<0) return 0;
		if(dp[i][j]!=-1) 
				return dp[i][j];
		if(s1[i]==s2[j]) return dp[i][j]=s1[i]+f(i-1,j-1,s1,s2,dp);
		return dp[i][j]=max(f(i-1,j,s1,s2,dp),f(i,j-1,s1,s2,dp));
	}

	int minimumDeleteSum(string s1, string s2) {
		int n=s1.size();
		int m=s2.size();
		int sum1=0,sum2=0;
		for(auto i:s1) 
				sum1+=i;
		for(auto i:s2) 
				sum2+=i;
		vector<vector<int>> dp(n,vector<int>(m,-1));
		return (sum1+sum2)-2*f(n-1,m-1,s1,s2,dp);
	}
};