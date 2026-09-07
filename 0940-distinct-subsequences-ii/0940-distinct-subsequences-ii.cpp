class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;

        long long dp = 1;
        long long last[26] = {};

        for (char c : s) {
            int x = c - 'a';

            long long newdp = (2 * dp - last[x] + MOD) % MOD;

            last[x] = dp;
            dp = newdp;
        }

        return (dp - 1 + MOD) % MOD;
    }
};