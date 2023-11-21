class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> hash;
        for (auto& num : nums) 
           hash[num - rev(num)]++;
        int count = 0;
        for (auto& [key, value] : hash) {
            long long pairs = ((1LL * value * (value - 1)) / 2LL) % MOD;
            count = (count + pairs) % MOD;
        }
        return count;
    }
private:
    const int MOD = 1e9 + 7;
    int rev(int x) {
        int result = 0;
        while (x > 0) {
            result = 10 * result + (x % 10);
            x /= 10;
        }
        return result;
    }
};