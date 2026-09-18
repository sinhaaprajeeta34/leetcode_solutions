class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, n), last(26, -1);

        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            first[c] = min(first[c], i);
            last[c] = i;
        }

        vector<pair<int, int>> intervals;

        for (int c = 0; c < 26; c++) {
            if (first[c] == n) continue;

            int l = first[c];
            int r = last[c];
            bool valid = true;

            for (int i = l; i <= r; i++) {
                int x = s[i] - 'a';

                // x occurs before l, so [l, r] can never contain
                // every occurrence of x.
                if (first[x] < l) {
                    valid = false;
                    break;
                }

                // Include all occurrences of x.
                r = max(r, last[x]);
            }

            if (valid)
                intervals.push_back({l, r});
        }

        // Earliest finishing interval first.
        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b) {
                 if (a.second != b.second)
                     return a.second < b.second;
                 return a.first < b.first;
             });

        vector<string> ans;
        int prevEnd = -1;

        for (auto &[l, r] : intervals) {
            if (l > prevEnd) {
                ans.push_back(s.substr(l, r - l + 1));
                prevEnd = r;
            }
        }

        return ans;
    }
};