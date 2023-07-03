class Solution {
public:
    int f(string &s1,string &s2,int ind1,int ind2,vector<vector<int>>&dp)
    {
        if(ind1<0 || ind2<0)
            return 0;
        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];
        if(s1[ind1]==s2[ind2])
            return dp[ind1][ind2]= 1+f(s1,s2,ind1-1,ind2-1,dp);
        return dp[ind1][ind2]=max(f(s1,s2,ind1-1,ind2,dp),f(s1,s2,ind1,ind2-1,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
       int n1=text1.length()-1,n2=text2.length()-1;
       vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        return f(text1,text2,n1,n2,dp);
    }
    int minDistance(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        return n1+n2-2*longestCommonSubsequence(word1,word2);
        
    }
};