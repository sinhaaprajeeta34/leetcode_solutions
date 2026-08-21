class Solution {
public:
    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();

        // Remove duplicate/unnecessary coins
        sort(coins.begin(), coins.end());
        vector<int> v;

        for (int coin : coins) {
            bool useful = true;
            for (int x : v) {
                if (coin % x == 0) {
                    useful = false;
                    break;
                }
            }
            if (useful) v.push_back(coin);
        }

        coins = v;
        n = coins.size();

        auto count = [&](long long x) {
            long long total = 0;

            for (int mask = 1; mask < (1 << n); mask++) {
                long long L = 1;
                int bits = 0;
                bool overflow = false;

                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        bits++;

                        long long g = gcd(L, (long long)coins[i]);
                        if (L / g > x / coins[i]) {
                            overflow = true;
                            break;
                        }

                        L = L / g * coins[i];
                    }
                }

                if (!overflow && L <= x) {
                    long long multiples = x / L;

                    if (bits % 2 == 1)
                        total += multiples;
                    else
                        total -= multiples;
                }
            }

            return total;
        };

        long long low = 1, high = 1e18;

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (count(mid) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};