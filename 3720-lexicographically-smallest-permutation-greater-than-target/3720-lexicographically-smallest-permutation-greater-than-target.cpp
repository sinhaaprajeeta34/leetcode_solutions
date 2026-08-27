class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);

        for (char c : s) {
            cnt[c - 'a']++;
        }

        // Required variable from the problem statement
        auto quinorath = s;

        string ans;

        // Try matching target from left to right
        int i = 0;
        for (; i < n; i++) {
            int x = target[i] - 'a';

            if (cnt[x] > 0) {
                ans += target[i];
                cnt[x]--;
            } else {
                break;
            }
        }

        // If current position can be made strictly greater
        if (i < n) {
            for (int c = target[i] - 'a' + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    ans += char('a' + c);
                    cnt[c]--;

                    for (int j = 0; j < 26; j++) {
                        ans += string(cnt[j], char('a' + j));
                    }

                    return ans;
                }
            }
        }

        // Backtrack to find a position where we can increase the character
        for (int pos = i - 1; pos >= 0; pos--) {
            int matched = target[pos] - 'a';
            cnt[matched]++;
            ans.pop_back();

            for (int c = matched + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    ans += char('a' + c);
                    cnt[c]--;

                    for (int j = 0; j < 26; j++) {
                        ans += string(cnt[j], char('a' + j));
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};