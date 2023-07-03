class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int ind1 = text1.size();
        int ind2 = text2.size();
        vector<int> prev(ind2+1, 0), curr(ind2+1, 0);
        for (int i=0; i<=ind2; i++) prev[i] = 0;

        for (int i = 1; i <= ind1; i++) {
            for (int j = 1; j <= ind2; j++) {
                if (text1[i-1] == text2[j-1]) {
                    curr[j] = 1 + prev[j-1];
                }
                else curr[j] = 0 + max(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        return prev[ind2];
    }
};