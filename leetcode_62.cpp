class Solution {
    public:
        int uniquePaths(int m, int n) {
            // 조합 C(m+n-2, m-1)을 계산 (m-1, n-1 중 더 작은 값을 사용)
            int N = m + n - 2;
            int k = min(m - 1, n - 1);
            long long res = 1;
            for (int i = 1; i <= k; i++) {
                res = res * (N - k + i) / i;
            }
            return res;
        }
    };
    