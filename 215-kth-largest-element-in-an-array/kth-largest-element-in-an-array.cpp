class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq ; 

        for (int i = 0 ; i < nums.size() ; i ++)
        {
            pq.push(nums[i]) ; 
        }
        int temp = 1 ; 
        while (temp != k)
        {
            pq.pop() ; 
            temp ++ ; 
        } 

        return pq.top() ; 
    }
};