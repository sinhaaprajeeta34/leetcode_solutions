class Solution {
public:

    void expand(string &s, int left, int right, int &start, int &maxLength) {

        while (left >= 0 && right < s.size() && s[left] == s[right]) {

            if (right - left + 1 > maxLength) {

                start = left;
                maxLength = right - left + 1;
            }

            left--;
            right++;
        }
    }

    string longestPalindrome(string s) {

        int start = 0;
        int maxLength = 1;

        for (int i = 0; i < s.size(); i++) {

            // Odd-length palindrome
            expand(s, i, i, start, maxLength);

            // Even-length palindrome
            expand(s, i, i + 1, start, maxLength);
        }

        return s.substr(start, maxLength);
    }
};