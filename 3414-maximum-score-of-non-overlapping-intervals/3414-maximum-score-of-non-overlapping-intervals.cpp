class Solution {
public:

    struct State {
        long long score;
        vector<int> indices;
    };

    // Returns true if a is better than b
    bool better(const State& a, const State& b) {

        if (a.score != b.score)
            return a.score > b.score;

        return a.indices < b.indices;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        // start, end, weight, original index
        vector<array<int, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        sort(a.begin(), a.end());

        // Sorted start times
        vector<int> starts(n);

        for (int i = 0; i < n; i++) {
            starts[i] = a[i][0];
        }

        // next[i] = first interval with start > end of i
        vector<int> nxt(n);

        for (int i = 0; i < n; i++) {
            nxt[i] = upper_bound(
                starts.begin(),
                starts.end(),
                a[i][1]
            ) - starts.begin();
        }

        /*
            dp[i][k]:
            Best answer using intervals from i onwards,
            selecting at most k intervals.
        */

        vector<vector<State>> dp(
            n + 1,
            vector<State>(5)
        );

        // dp[n][k] = score 0, empty indices
        for (int k = 0; k <= 4; k++) {
            dp[n][k] = {0, {}};
        }

        for (int i = n - 1; i >= 0; i--) {

            for (int k = 1; k <= 4; k++) {

                // Option 1: Skip current interval
                State skip = dp[i + 1][k];

                // Option 2: Take current interval
                State take = dp[nxt[i]][k - 1];

                take.score += a[i][2];
                take.indices.push_back(a[i][3]);

                sort(take.indices.begin(), take.indices.end());

                // Choose maximum score.
                // If score is same, choose lexicographically smaller indices.
                if (better(take, skip))
                    dp[i][k] = take;
                else
                    dp[i][k] = skip;
            }
        }

        return dp[0][4].indices;
    }
};