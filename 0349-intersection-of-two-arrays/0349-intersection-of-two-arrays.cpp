class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>m;
        set<int>s;
        for(int i=0;i<nums1.size();i++)
          m[nums1[i]]++;
        for(auto &it:nums2)
        {
          if(m.find(it)!=m.end())
            s.insert(it);
        }
        vector<int>v(s.begin(),s.end());
        return v;
    }
};