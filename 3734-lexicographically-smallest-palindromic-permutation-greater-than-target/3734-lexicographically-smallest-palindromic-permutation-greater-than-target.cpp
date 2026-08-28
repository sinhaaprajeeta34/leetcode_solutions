class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        // Check whether palindrome permutation is possible
        int odd = 0;
        char mid = '\0';

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2) {
                odd++;
                mid = 'a' + i;
            }
        }

        if (odd > 1)
            return "";

        // Frequency of first half
        vector<int> halfFreq(26);
        for (int i = 0; i < 26; i++)
            halfFreq[i] = freq[i] / 2;

        int m = s.size() / 2;

        auto buildPalindrome = [&](const string& half) {
            string ans = half;

            if (mid != '\0')
                ans += mid;

            for (int i = half.size() - 1; i >= 0; i--)
                ans += half[i];

            return ans;
        };

        string prefix = target.substr(0, m);

        // Case 1: Can we exactly match target's first half?
        vector<int> temp = halfFreq;
        bool possible = true;

        for (char c : prefix) {
            if (--temp[c - 'a'] < 0) {
                possible = false;
                break;
            }
        }

        if (possible) {
            string candidate = buildPalindrome(prefix);

            if (candidate > target)
                return candidate;
        }

        /*
           Find the rightmost position where:
           target prefix can be matched,
           and current character can be increased.
        */
        temp = halfFreq;

        int bestPos = -1;
        char bestChar = '\0';
        vector<int> bestFreq;

        for (int i = 0; i < m; i++) {

            // Find smallest available character > prefix[i]
            for (int c = prefix[i] - 'a' + 1; c < 26; c++) {
                if (temp[c] > 0) {
                    bestPos = i;
                    bestChar = 'a' + c;
                    bestFreq = temp;
                    break;
                }
            }

            // Continue matching target prefix
            int cur = prefix[i] - 'a';

            if (temp[cur] == 0)
                break;

            temp[cur]--;
        }

        if (bestPos == -1)
            return "";

        // Build answer:
        // same prefix + smallest greater character + sorted remaining chars
        string half = prefix.substr(0, bestPos);

        half += bestChar;
        bestFreq[bestChar - 'a']--;

        for (int c = 0; c < 26; c++) {
            half.append(bestFreq[c], char('a' + c));
        }

        return buildPalindrome(half);
    }
};