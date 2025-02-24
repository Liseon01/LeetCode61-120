// dfs solution (time execeed)
class Solution {
    public:
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            int m = obstacleGrid.size();
            if(m == 0) return 0;
            int n = obstacleGrid[0].size();
            
            // 시작점이나 도착점에 장애물이 있으면 경로가 없음
            if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1)
                return 0;
            
            int count = 0; 
            dfs(obstacleGrid, 0, 0, count, m, n);
            return count;
        }
        
    private:
        void dfs(vector<vector<int>>& obstacleGrid, int x, int y, int& count, int m, int n) {
            // 도착점에 도달하면 count 증가
            if(x == m - 1 && y == n - 1) {
                count++;
                return;
            }
            
            // 아래쪽으로 이동
            if(x + 1 < m && obstacleGrid[x+1][y] == 0) {
                dfs(obstacleGrid, x+1, y, count, m, n);
            }
            
            // 오른쪽으로 이동
            if(y + 1 < n && obstacleGrid[x][y+1] == 0) {
                dfs(obstacleGrid, x, y+1, count, m, n);
            }
        }
    };
// dp solutuin   
    class Solution {
        public:
            int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
                int m = obstacleGrid.size();
                if(m == 0) return 0;
                int n = obstacleGrid[0].size();
                
                // 시작점이 장애물인 경우 바로 0 반환
                if(obstacleGrid[0][0] == 1) return 0;
                
                vector<vector<int>> dp(m, vector<int>(n, 0));
                dp[0][0] = 1;
                
                // 첫 번째 열 채우기
                for (int i = 1; i < m; i++) {
                    dp[i][0] = (obstacleGrid[i][0] == 0 && dp[i-1][0] == 1) ? 1 : 0;
                }
                
                // 첫 번째 행 채우기
                for (int j = 1; j < n; j++) {
                    dp[0][j] = (obstacleGrid[0][j] == 0 && dp[0][j-1] == 1) ? 1 : 0;
                }
                
                // 나머지 셀 채우기
                for (int i = 1; i < m; i++) {
                    for (int j = 1; j < n; j++) {
                        if(obstacleGrid[i][j] == 0) {
                            dp[i][j] = dp[i-1][j] + dp[i][j-1];
                        } else {
                            dp[i][j] = 0;
                        }
                    }
                }
                
                return dp[m-1][n-1];
            }
        };
        