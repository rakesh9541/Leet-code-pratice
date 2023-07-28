class Solution {
public:
    vector<int> dp;
    bool canWin(int used, const int &maxChoosableInteger, int desiredTotal) {
        if (dp[used] != -1) 
            return dp[used];
        for (int i = maxChoosableInteger, bits = 1 << (maxChoosableInteger - 1); i >= 1; --i, bits >>= 1) {
            if ((used & bits) != 0) continue;
            if (i >= desiredTotal || !canWin(used | bits, maxChoosableInteger, desiredTotal - i)) {
                dp[used] = 1;
                return true;
            }
        }
        dp[used] = 0;
        return false;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal) 
            return true;
        int sum = ((maxChoosableInteger + 1) * maxChoosableInteger) / 2;
        if (sum < desiredTotal) 
            return false;
        dp = vector<int>(1 << maxChoosableInteger, -1);
        return canWin(0, maxChoosableInteger, desiredTotal);
    }
};
