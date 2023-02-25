class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>m;
        int length=0;
        int j=0;
        int maxi = 0;
        for(int i=0; i<s.size(); i++)
        {
            m[s[i]]++;
            length++;
            while(m[s[i]]>1)
            {
                m[s[j]]--;
                length--;
                j++;
            }
            if(length>=maxi)
                maxi = length;
        }
        return maxi;
    }
};