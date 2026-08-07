class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        if (m == 1 && n == 1)
            return 0;

        vector<vector<vector<bool>>> vis(
            m,
            vector<vector<bool>>(n, vector<bool>(k + 1, false))
        );

        queue<vector<int>> q;
        q.push({0, 0, k});
        vis[0][0][k] = true;

        int steps = 0;

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                auto curr = q.front();
                q.pop();

                int x = curr[0];
                int y = curr[1];
                int rem = curr[2];

                if (x == m - 1 && y == n - 1)
                    return steps;

                for (int i = 0; i < 4; i++) {

                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                        continue;

                    if (grid[nx][ny] == 0 && !vis[nx][ny][rem]) {

                        vis[nx][ny][rem] = true;
                        q.push({nx, ny, rem});
                    }

                    else if (grid[nx][ny] == 1 && rem > 0 &&
                             !vis[nx][ny][rem - 1]) {

                        vis[nx][ny][rem - 1] = true;
                        q.push({nx, ny, rem - 1});
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};