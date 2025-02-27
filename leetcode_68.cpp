class Solution {
    public:
        vector<string> fullJustify(vector<string>& words, int maxWidth) {
            vector<string> result;
            int n = words.size();
            int index = 0;
    
            while (index < n) {
                int totalChars = words[index].size();
                int last = index + 1;
    
                // 현재 줄에 넣을 수 있는 단어 결정
                while (last < n && totalChars + words[last].size() + (last - index) <= maxWidth) {
                    totalChars += words[last].size();
                    last++;
                }
    
                int gaps = last - index - 1;
                string line = words[index];
    
                // 마지막 줄이거나 한 단어만 있는 경우: 왼쪽 정렬
                if (last == n || gaps == 0) {
                    for (int i = index + 1; i < last; i++) {
                        line += " " + words[i];
                    }
                    line += string(maxWidth - line.size(), ' '); // 남은 공간 공백 채우기
                }
                // 그 외의 경우: 균등 분배
                else {
                    int spaces = (maxWidth - totalChars) / gaps;
                    int extraSpaces = (maxWidth - totalChars) % gaps;
    
                    for (int i = index + 1; i < last; i++) {
                        int spaceCount = spaces + (i - index <= extraSpaces ? 1 : 0);
                        line += string(spaceCount, ' ') + words[i];
                    }
                }
    
                result.push_back(line);
                index = last;
            }
    
            return result;
        }
    };
    