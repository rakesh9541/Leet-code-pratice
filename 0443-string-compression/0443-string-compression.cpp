
class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> ans;
        for(int i=0; i<chars.size(); i++) {
            int l = i;
            int r = i;
            while(r<chars.size() && chars[l]==chars[r]) 
                r++; 
            if(r-l == 1) 
                ans.push_back(chars[l]);
            else {
                ans.push_back(chars[l]);
                if(r-l >=10) {
                    string a = to_string(r-l);
                    for(auto x: a) 
                        ans.push_back(x);
                }
                else
                ans.push_back('0'+(r-l));
            }
            i = r-1;
        }
        for(int i=0; i<ans.size(); i++)
        {
            if(i<chars.size()) 
                chars[i] = ans[i];
        }
        return ans.size();
    }
};