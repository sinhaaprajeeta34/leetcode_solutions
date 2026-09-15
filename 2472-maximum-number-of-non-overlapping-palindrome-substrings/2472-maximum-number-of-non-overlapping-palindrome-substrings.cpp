class Solution {
public:
    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }

    int maxPalindromes(string s, int k) {
        int n = s.size();

        vector<int> dp(n + 1, 0);

        for (int i = k; i <= n; i++) {

            // Don't take a palindrome ending at i-1
            dp[i] = dp[i - 1];

            // Palindrome of length k
            if (isPalindrome(s, i - k, i - 1)) {
                dp[i] = max(dp[i], dp[i - k] + 1);
            }

            // Palindrome of length k + 1
            if (i - k - 1 >= 0 &&
                isPalindrome(s, i - k - 1, i - 1)) {
                
                dp[i] = max(dp[i], dp[i - k - 1] + 1);
            }
        }

        return dp[n];
    }
};