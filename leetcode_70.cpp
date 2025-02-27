// dfs (time exeed)
class Solution {
    public:
        int climbStairs(int n) {
            int cnt = 0;
            int head = n;
            dfs(n, head, cnt);
            return cnt;
        }
    private:
        void dfs(int& n, int& head, int& cnt){
            if(head == 0) {
                cnt++;
                return;
            }
            if(head < 0) return;
    
            head --;
            dfs(n, head, cnt);
            head ++;
    
            head -=2;
            dfs(n, head, cnt);
            head +=2;
        }
    };
// 피보나치 수열
    class Solution {
        public:
            int climbStairs(int n) {
                if(n <= 2) return n;
                int a = 1, b = 2;
                for(int i = 3; i <= n; i++){
                    int tmp = a + b;
                    a = b;
                    b = tmp;
                }
                return b;
            }
        };
        