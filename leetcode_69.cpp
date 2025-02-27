// 이진 탐색 방법
class Solution {
    public:
        int mySqrt(int x) {
            if(x == 0) return 0;
            int left = 1, right = x, res;
            while(left <= right) {
                long long middle = left + (right - left) / 2; // 오버플로우 방지
                if(middle * middle == x)
                    return middle;
                else if(middle * middle < x) {
                    left = middle + 1;
                    res = middle;
                }
                else {
                    right = middle - 1;
                }
            }
            return res;
        }
    };
// 뉴턴 랩슨 방법
class Solution {
    public:
        int mySqrt(int x) {
            if(x < 2) return x; // 0과 1은 그대로 반환
            
            long r = x;
            while(r > x / r)
                r = (r + x / r) / 2;
            return r;
        }
    };
    