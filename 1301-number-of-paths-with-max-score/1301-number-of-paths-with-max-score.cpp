class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {

        int n = board.size();
        const int MOD = 1000000007;

        // score[i][j] = maximum score from S to (i,j)
        // ways[i][j]  = number of ways to get that score
        vector<vector<int>> score(n, vector<int>(n, -1));
        vector<vector<int>> ways(n, vector<int>(n, 0));

        // Starting point S
        score[n - 1][n - 1] = 0;
        ways[n - 1][n - 1] = 1;

        // Bottom-right -> Top-left
        for (int i = n - 1; i >= 0; i--) {

            for (int j = n - 1; j >= 0; j--) {

                // S
                if (i == n - 1 && j == n - 1)
                    continue;

                // Obstacle
                if (board[i][j] == 'X')
                    continue;

                int best = -1;
                long long cnt = 0;

                // Down
                if (i + 1 < n && score[i + 1][j] != -1) {

                    if (score[i + 1][j] > best) {
                        best = score[i + 1][j];
                        cnt = ways[i + 1][j];
                    }
                    else if (score[i + 1][j] == best) {
                        cnt += ways[i + 1][j];
                    }
                }

                // Right
                if (j + 1 < n && score[i][j + 1] != -1) {

                    if (score[i][j + 1] > best) {
                        best = score[i][j + 1];
                        cnt = ways[i][j + 1];
                    }
                    else if (score[i][j + 1] == best) {
                        cnt += ways[i][j + 1];
                    }
                }

                // Diagonal
                if (i + 1 < n && j + 1 < n &&
                    score[i + 1][j + 1] != -1) {

                    if (score[i + 1][j + 1] > best) {
                        best = score[i + 1][j + 1];
                        cnt = ways[i + 1][j + 1];
                    }
                    else if (score[i + 1][j + 1] == best) {
                        cnt += ways[i + 1][j + 1];
                    }
                }

                // No path to this cell
                if (best == -1)
                    continue;

                // Add current cell's value
                int value = 0;

                if (board[i][j] >= '0' &&
                    board[i][j] <= '9') {

                    value = board[i][j] - '0';
                }

                score[i][j] = best + value;
                ways[i][j] = cnt % MOD;
            }
        }

        // E cannot be reached
        if (score[0][0] == -1)
            return {0, 0};

        return {
            score[0][0],
            ways[0][0]
        };
    }
};