class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long power(long long a, long long b) {
        long long ans = 1;
        while (b) {
            if (b & 1)
                ans = ans * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return ans;
    }

    int numberOfSets(int n, int k) {
        int N = n + k - 1;
        int R = 2 * k;

        long long num = 1, den = 1;

        for (int i = 0; i < R; i++) {
            num = num * (N - i) % MOD;
            den = den * (i + 1) % MOD;
        }

        return num * power(den, MOD - 2) % MOD;
    }
};