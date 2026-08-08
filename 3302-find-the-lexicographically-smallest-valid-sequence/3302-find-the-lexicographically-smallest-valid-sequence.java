class Solution {
    public int[] validSequence(String word1, String word2) {

        int n = word1.length();
        int m = word2.length();

        // dp[i] = word1[i...] se word2 ke
        // maximum kitne characters match ho sakte hain
        int[] dp = new int[n + 1];

        int j = m - 1;

        // Suffix matching
        for (int i = n - 1; i >= 0; i--) {

            dp[i] = dp[i + 1];

            if (j >= 0 && word1.charAt(i) == word2.charAt(j)) {
                dp[i]++;
                j--;
            }
        }

        int[] ans = new int[m];

        int i = 0;
        j = 0;

        // First part:
        // Lexicographically smallest index choose karna
        while (i < n && j < m) {

            if (word1.charAt(i) == word2.charAt(j)) {

                // Exact match
                ans[j] = i;
                j++;

            } else {

                // Is index ko one allowed modification ke liye use kar sakte hain
                if (dp[i + 1] >= m - 1 - j) {

                    ans[j] = i;
                    j++;
                    i++;

                    // Modification use ho gayi
                    break;
                }
            }

            i++;
        }

        // Word2 complete nahi hua
        if (j < m && i == n) {
            return new int[0];
        }

        // Remaining characters exact match hone chahiye
        while (j < m && i < n) {

            if (word1.charAt(i) == word2.charAt(j)) {
                ans[j] = i;
                j++;
            }

            i++;
        }

        // Still incomplete => no valid sequence
        if (j < m) {
            return new int[0];
        }

        return ans;
    }
}